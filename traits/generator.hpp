#ifndef __LIBTRAITS_TRAITS_GENERATOR_HPP__
#define __LIBTRAITS_TRAITS_GENERATOR_HPP__

#include "libtraits/traits/updater.hpp"
#include "libtraits/traits/packer.hpp"

namespace libtraits { namespace traits {

template<typename T>
struct generator {
    template<typename IT>
    static void generate(IT& it, T& t) {
	updater<T>::update(t);
	packer<T>::pack(it, t);
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_GENERATOR_HPP__ */
