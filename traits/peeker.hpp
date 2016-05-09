#ifndef __LIBTRAITS_TRAITS_PEEKER_HPP__
#define __LIBTRAITS_TRAITS_PEEKER_HPP__

namespace libtraits { namespace traits {

template<typename T>
struct peeker;

template<>
struct peeker<char> {
    template<typename IT>
    static bool peek(const IT& it, char& t) {
	t = (char)*it;
	return true;
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_PEEKER_HPP__ */
