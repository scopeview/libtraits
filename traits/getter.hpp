#ifndef __LIBTRAITS_TRAITS_GETTER_HPP__
#define __LIBTRAITS_TRAITS_GETTER_HPP__

namespace libtraits { namespace traits {

template<typename T, typename U, bool B = std::is_base_of<U, T>::value>
struct getter;

template<typename T, typename U>
struct getter<T, U, true> {
    static U& get(T& t) {
	return static_cast<U&>(t);
    }
    static const U& get(const T& t) {
	return static_cast<const U&>(t);
    }
};

template<typename T, typename U>
struct getter<T, U, false> {
    static U& get(T& t) {
	U* ptr;
	t.get(&ptr);
	return *ptr;
    }
    static const U& get(const T& t) {
	const U* ptr;
	t.get(&ptr);
	return *ptr;
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_GETTER_HPP__ */
