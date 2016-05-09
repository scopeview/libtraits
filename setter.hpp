#ifndef __LIBTRAITS_SETTER_HPP__
#define __LIBTRAITS_SETTER_HPP__

#include "libtraits/traits/setter.hpp"

namespace libtraits {

template<typename T, typename U>
void set(T& t, const U& u) {
    traits::setter<T, U>::set(t, u);
}

}
#endif	/* __LIBTRAITS_SETTER_HPP__ */
