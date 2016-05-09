#ifndef __LIBTRAITS_TRAITS_UNPACKER_BY_GETTER_HPP__
#define __LIBTRAITS_TRAITS_UNPACKER_BY_GETTER_HPP__

#include <tuple>
#include "libtraits/traits/getter.hpp"
#include "libtraits/traits/unpacker.hpp"

namespace libtraits { namespace traits {

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename T>
struct unpacker_getter_sequence;

#define DEFINE_UNPACKER_GETTER_SEQUENCE(CLASS, GETTER)		\
    template<typename T>					\
    struct unpacker_getter_sequence {				\
	unpacker_getter_sequence() = delete;			\
	typedef std::tuple<GETTER> sequence_type;		\
    };								\
/***/


////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
namespace helper {

template<typename T, typename BaseClassSequence>
struct unpacker_by_getter;

template<typename T, typename B1, typename... BRest>
struct unpacker_by_getter<T, std::tuple<B1, BRest...>> {
    template<typename IT>
    static void unpack(IT& it, T& t) {
	unpacker<B1>::unpack(it, getter<T, B1>::get(t));
	unpacker_by_getter<T, std::tuple<BRest...>>::unpack(it, t);
    }
};

template<typename T, typename B1>
struct unpacker_by_getter<T, std::tuple<B1>> {
    template<typename IT>
    static void unpack(IT& it, T& t) {
	unpacker<B1>::unpack(it, getter<T, B1>::get(t));
    }
};

}

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename T>
struct unpacker_by_getter {
    typedef typename unpacker_getter_sequence<T>::sequence_type sequence_type;

    template<typename IT>
    static void unpack(IT& it, T& t) {
	helper::unpacker_by_getter<T, sequence_type>::unpack(it, t);
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_UNPACKER_BY_GETTER_HPP__ */
