#ifndef __ESTD_TEMPLATE_PACKER_HPP__
#define __ESTD_TEMPLATE_PACKER_HPP__

#include "libtraits/traits/packer.hpp"

namespace libtraits {

template<typename IT, typename... T>
void pack(IT& it, const T&... t) {
    static_assert(sizeof...(T) >= 1, "");
    traits::packer<T...>::pack(it, t...);
}

template<typename IT, typename... T>
void pack(IT& it, const std::tuple<T...>& t) {
    traits::packer<std::tuple<T...>>::pack(it, t);
}

}
#endif	/* __ESTD_TEMPLATE_PACKER_HPP__ */
