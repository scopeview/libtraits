#ifndef __LIBTRAITS_GENERATOR_HPP__
#define __LIBTRAITS_GENERATOR_HPP__

#include "libtraits/traits/generator.hpp"

namespace libtraits {

template<typename IT, typename T>
void generate(IT& it, T& t)
{
    traits::generator<T>::generate(it, t);
}

}
#endif	/* __LIBTRAITS_GENERATOR_HPP__ */
