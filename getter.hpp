#ifndef __ESTD_TEMPLATE_GETTER_HPP__
#define __ESTD_TEMPLATE_GETTER_HPP__

#include "libtraits/traits/getter.hpp"

namespace libtraits {

template<typename U, typename T>
U& get(T& t) {
    return traits::getter<T, U>::get(t);
}

template<typename U, typename T>
const U& get(const T& t) {
    return traits::getter<T, U>::get(t);
}

}
#endif	/* __ESTD_TEMPLATE_GETTER_HPP__ */
