#ifndef __LIBTRAITS_TRAITS_PACKER_HPP__
#define __LIBTRAITS_TRAITS_PACKER_HPP__

namespace libtraits { namespace traits {

template<typename T, typename... Rest>
struct packer {
    template<typename IT>
    static void pack(IT& it, const T& t, const Rest&... rest) {
	packer<T>::pack(it, t);
	packer<Rest...>::pack(it, rest...);
    }
};

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename T, int N, int End, bool is_last = (N+1)==End>
struct tuple_packer;

template<typename... T, int N, int End>
struct tuple_packer<std::tuple<T...>, N, End, false> {
    typedef std::tuple<T...> tuple_type;
    typedef typename std::tuple_element<N, tuple_type>::type current_type;

    template<typename IT>
    static void pack(IT& it, const tuple_type& t) {
	packer<current_type>::pack(it, std::get<N>(t));
	tuple_packer<tuple_type, N+1, End>::pack(it, t);
    }
};

template<typename... T, int N, int End>
struct tuple_packer<std::tuple<T...>, N, End, true> {
    typedef std::tuple<T...> tuple_type;
    typedef typename std::tuple_element<N, tuple_type>::type current_type;

    template<typename IT>
    static void pack(IT& it, const tuple_type& t) {
	packer<current_type>::pack(it, std::get<N>(t));
    }
};

template<typename... T, int N, bool is_last>
struct tuple_packer<std::tuple<T...>, N, 0, is_last> {
    template<typename IT>
    static void pack(IT& it, const std::tuple<T...>& t) {}
};

}

////////////////
template<typename... T>
struct packer<std::tuple<T...>> {
    typedef std::tuple<T...> tuple_type;

    template<std::size_t From = 0, typename IT>
    static void pack(IT& it, const tuple_type& t) {
	helper::tuple_packer<tuple_type, From,
			     std::tuple_size<tuple_type>::value>::pack(it, t);
    }
};

template<>
struct packer<std::tuple<>> {
    template<std::size_t From = 0, typename IT>
    static void pack(IT& it, const std::tuple<>& t) {}
};

}}
#endif	/* __LIBTRAITS_TRAITS_PACKER_HPP__ */

