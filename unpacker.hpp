#ifndef __LIBTRAITS_UNPACKER_HPP__
#define __LIBTRAITS_UNPACKER_HPP__

#include "libtraits/traits/unpacker.hpp"

namespace libtraits {

template<typename IT, typename... T>
void unpack(IT& it, T&... t) {
    static_assert(sizeof...(T) >= 1, "");
    traits::unpacker<T...>::unpack(it, t...);
}

template<typename IT, typename... T>
void unpack(IT& it, std::tuple<T...> t) {
    traits::unpacker<std::tuple<T...>>::unpack(it, t);
}

}
#endif	/* __LIBTRAITS_UNPACKER_HPP__ */
