#ifndef __LIBTRAITS_TRAITS_UPDATER_HPP__
#define __LIBTRAITS_TRAITS_UPDATER_HPP__

#include "libtraits/traits/updater.hpp"

namespace libtraits { namespace traits {

template<typename T, typename... Rest>
struct updater {
     static void update(T& t, Rest&... rest) {
	 updater<T>::update(t);
	 updater<Rest...>::update(rest...);
    }
};

template<typename T>
struct updater<T> {
    static void update(T& t) {}
};

}}
#endif	/* __LIBTRAITS_TRAITS_UPDATER_HPP__ */
