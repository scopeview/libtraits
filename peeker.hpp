#ifndef __LIBTRAITS_PEEKER_HPP__
#define __LIBTRAITS_PEEKER_HPP__

#include "libtraits/traits/peeker.hpp"

namespace libtraits {

// if peek a T successfully, return true
template<typename IT, typename T>
bool peek(const IT& it, T& t) {
    return traits::peeker<T>::peek(it, t);
}

}
#endif	/* __LIBTRAITS_PEEKER_HPP__ */
