#ifndef __LIBTRAITS_TRAITS_PACKER_SIZER_HPP__
#define __LIBTRAITS_TRAITS_PACKER_SIZER_HPP__

#include "libtraits/traits/packer_sizer.hpp"

namespace libtraits { namespace traits {

template<typename T, typename... Rest>
struct packer_sizer {
     static size_t size(const T& t, const Rest&... rest) {
	 return packer_sizer<T>::size(t) + packer_sizer<Rest...>::size(rest...);
    }
};

template<typename T>
struct packer_sizer<T> {
    static size_t size(const T& t) {
	return sizeof(T);
    }
};

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename T, int N, int End, bool is_last = (N+1)==End>
struct tuple_packer_sizer;

template<typename... T, int N, int End>
struct tuple_packer_sizer<std::tuple<T...>, N, End, false> {
     static size_t size(const std::tuple<T...>& t) {
	 typedef std::tuple<T...> tuple_type;
	 typedef typename std::tuple_element<N, tuple_type>::type current_type;

	 return packer_sizer<current_type>::size(std::get<N>(t))
	     + tuple_packer_sizer<std::tuple<T...>, N+1, End>::size(t);
     }
};

template<typename... T, int N, bool is_last>
struct tuple_packer_sizer<std::tuple<T...>, N, 0, is_last> {
    static size_t size(const std::tuple<T...>& t) {
	return 0;
    }
};

template<typename... T, int N, int End>
struct tuple_packer_sizer<std::tuple<T...>, N, End, true> {
    static size_t size(const std::tuple<T...>& t) {
	typedef std::tuple<T...> tuple_type;
	typedef typename std::tuple_element<N, tuple_type>::type current_type;

	return packer_sizer<current_type>::size(std::get<N>(t));
    }
};

}

////////////////
template<typename... T>
struct packer_sizer<std::tuple<T...>> {
    static size_t size(const std::tuple<T...>& t) {
	typedef std::tuple<T...> tuple_type;
	return helper::tuple_packer_sizer<tuple_type, 0,
					  std::tuple_size<tuple_type>::value>::size(t);
    }
};

template<>
struct packer_sizer<std::tuple<>> {
    static size_t size(const std::tuple<>& t) {
	return 0;
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_PACKER_SIZER_HPP__ */
