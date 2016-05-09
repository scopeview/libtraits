#ifndef __LIBTRAITS_VALIDATOR_HPP__
#define __LIBTRAITS_VALIDATOR_HPP__

#include "libtraits/traits/validator.hpp"

namespace libtraits {

template<typename... T>
void validate(T&... t) {
    traits::validator<T...>::validate(t...);
}

}
#endif	/* __LIBTRAITS_VALIDATOR_HPP__ */
