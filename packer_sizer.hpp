#ifndef __LIBTRAITS_PACKER_SIZER_HPP__
#define __LIBTRAITS_PACKER_SIZER_HPP__

#include "libtraits/traits/packer_sizer.hpp"

namespace libtraits {

template<typename... T>
size_t packer_size(const T&... t) {
    return traits::packer_sizer<T...>::size(t...);
}

template<typename... T>
size_t packer_size(const std::tuple<T...>& t) {
    return traits::packer_sizer<std::tuple<T...>>::size(t);
}

}
#endif	/* __LIBTRAITS_PACKER_SIZER_HPP__ */
