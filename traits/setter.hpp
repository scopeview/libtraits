#ifndef __LIBTRAITS_TRAITS_SETTER_HPP__
#define __LIBTRAITS_TRAITS_SETTER_HPP__

#include "libtraits/traits/getter.hpp"

namespace libtraits { namespace traits {

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename T, typename B, bool is_base = std::is_base_of<B, T>::value>
struct setter;

template<typename T, typename B>
struct setter<T, B, true> {
    static void set(T& t, const B& b) {
	static_cast<B&>(t) = b;
    }
};

template<typename T, typename B>
struct setter<T, B, false> {
    static void set(T& t, const B& b) {
	t.set(b);
    }
};

}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename T, typename... B>
struct setter;

template<typename T, typename B>
struct setter<T, B> {
    static void set(T& t, const B& b) {
	helper::setter<T, B>::set(t, b);
    }
};

template<typename T, typename B, typename B1>
struct setter<T, B, B1> {
    static void set(T& t, const B1& b1) {
	B& b = getter<T, B>::get(t);
	setter<B, B1>::set(b, b1);
    }
};

template<typename T, typename B, typename B1, typename B2>
struct setter<T, B, B1, B2> {
    static void set(T& t, const B2& b2) {
	B& b = getter<T, B>::get(t);
	B1& b1 = getter<B, B1>::get(b);
	setter<B1, B2>::set(b1, b2);
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_SETTER_HPP__ */
