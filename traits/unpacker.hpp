#ifndef __LIBTRAITS_TRAITS_UNPACKER_HPP__
#define __LIBTRAITS_TRAITS_UNPACKER_HPP__

namespace libtraits { namespace traits {

template<typename T, typename... Rest>
struct unpacker {
    template<typename IT>
    static void unpack(IT& it, T& t, Rest&... rest) {
	unpacker<T>::unpack(it, t);
	unpacker<Rest...>::unpack(it, rest...);
    }

    template<typename IT>
    static void unpack(IT& it, IT& it_end, T& t, Rest&... rest) {
	unpacker<T>::unpack(it, it_end, t);
	unpacker<Rest...>::unpack(it, it_end, rest...);
    }
};

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename T, int N, int End, bool is_last = (N+1)==End>
struct tuple_unpacker;

template<typename... T, int N, int End>
struct tuple_unpacker<std::tuple<T...>, N, End, false> {
    typedef std::tuple<T...> tuple_type;
    typedef typename std::tuple_element<N, tuple_type>::type current_type;

    template<typename IT>
    static void unpack(IT& it, std::tuple<T...>& t) {
	unpacker<current_type>::unpack(it, std::get<N>(t));
	tuple_unpacker<tuple_type, N+1, End>::unpack(it, t);
    }

    template<typename IT>
    static void unpack(IT& it, IT& it_end, std::tuple<T...>& t) {
	unpacker<current_type>::unpack(it, it_end, std::get<N>(t));
	tuple_unpacker<tuple_type, N+1, End>::unpack(it, it_end, t);
    }
};

template<typename... T, int N, int End>
struct tuple_unpacker<std::tuple<T...>, N, End, true> {
    typedef std::tuple<T...> tuple_type;
    typedef typename std::tuple_element<N, tuple_type>::type current_type;

    template<typename IT>
    static void unpack(IT& it, std::tuple<T...>& t) {
	unpacker<current_type>::unpack(it, std::get<N>(t));
    }

    template<typename IT>
    static void unpack(IT& it, IT& it_end, std::tuple<T...>& t) {
	unpacker<current_type>::unpack(it, it_end, std::get<N>(t));
    }
};

}

////////////////
template<typename... T>
struct unpacker<std::tuple<T...>> {
    typedef std::tuple<T...> tuple_type;

    template<std::size_t From = 0, typename IT>
	static void unpack(IT& it, std::tuple<T...>& t) {
	helper::tuple_unpacker<tuple_type, From, 
			       std::tuple_size<tuple_type>::value>::unpack(it, t);
    }

    template<std::size_t From = 0, typename IT>
	static void unpack(IT& it, IT& it_end, std::tuple<T...>& t) {
	helper::tuple_unpacker<tuple_type, From, 
			       std::tuple_size<tuple_type>::value>::unpack(it, it_end, t);
    }
};

template<>
struct unpacker<std::tuple<>> {
    template<std::size_t From = 0, typename IT>
	static void unpack(IT& it, const std::tuple<>& t) {}

    template<std::size_t From = 0, typename IT>
	static void unpack(IT& it, IT& it_end, const std::tuple<>& t) {}
};

}}
#endif	/* __LIBTRAITS_TRAITS_UNPACKER_HPP__ */
