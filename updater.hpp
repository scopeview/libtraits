#ifndef __LIBTRAITS_UPDATER_HPP__
#define __LIBTRAITS_UPDATER_HPP__

#include "libtraits/traits/updater.hpp"

namespace libtraits {

template<typename... T>
void update(T&... t) {
    traits::updater<T...>::update(t...);
}

}
#endif	/* __LIBTRAITS_UPDATER_HPP__ */
