#ifndef __LIBTRAITS_TRAITS_PACKER_BY_GETTER_HPP__
#define __LIBTRAITS_TRAITS_PACKER_BY_GETTER_HPP__

#include <tuple>
#include "libtraits/traits/getter.hpp"
#include "libtraits/traits/packer.hpp"

namespace libtraits { namespace traits {

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename T>
struct packer_getter_sequence;

#define DEFINE_CLASS_SUBCLASS(CLASS, GETTER)			\
    template<typename T>					\
    struct packer_getter_sequence {				\
	packer_getter_sequence() = delete;			\
	typedef std::tuple<GETTER> sequence_type;		\
    };								\
/***/


////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename T, typename BaseClassSequence>
struct packer_by_getter;

template<typename T, typename B1, typename... BRest>
struct packer_by_getter<T, std::tuple<B1, BRest...>> {
    template<typename IT>
    static void pack(IT& it, const T& t) {
	packer<B1>::pack(it, getter<T, B1>::get(t));
	packer_by_getter<T, std::tuple<BRest...>>::pack(it, t);
    }
};

template<typename T, typename B1>
struct packer_by_getter<T, std::tuple<B1>> {
    template<typename IT>
    static void pack(IT& it, const T& t) {
	packer<B1>::pack(it, getter<T, B1>::get(t));
    }
};

}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename T>
struct packer_by_getter {
    typedef typename packer_getter_sequence<T>::sequence_type sequence_type;

    template<typename IT>
    static void pack(IT& it, const T& t) {
	helper::packer_by_getter<T, sequence_type>::pack(it, t);
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_PACKER_BY_GETTER_HPP__ */
