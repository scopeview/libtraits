#ifndef __LIBTRAITS_MODULER_HPP__
#define __LIBTRAITS_MODULER_HPP__

#include "libtraits/traits/moduler.hpp"

namespace libtraits {

template<typename M>
int get_module_id(const M& m) {
    return traits::moduler<M>::get_id(m);
}

template<typename M>
const char* get_module_name(const M& m)
{
    return traits::moduler<M>::get_name(m);
}

}
#endif	/* __LIBTRAITS_MODULER_HPP__ */
