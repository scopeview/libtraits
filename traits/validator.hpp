#ifndef __LIBTRAITS_TRAITS_VALIDATOR_HPP__
#define __LIBTRAITS_TRAITS_VALIDATOR_HPP__

namespace libtraits { namespace traits {

template<typename T, typename... Rest>
struct validator {
    static void validate(const T& t, const Rest&... rest) {
	validator<T>::validate(t);
	validator<Rest...>::validate(rest...);
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_VALIDATOR_HPP__ */
