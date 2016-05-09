#ifndef __LIBTRAITS_TRAITS_PARSER_HPP__
#define __LIBTRAITS_TRAITS_PARSER_HPP__

#include <memory>
#include "libtraits/traits/unpacker.hpp"

namespace libtraits { namespace traits {

template<typename T>
struct parser {
    template<typename IT>
    static std::unique_ptr<T> parse(IT& it) {
	std::unique_ptr<T> output(new T);
	unpacker<T>::unpack(it, *output);
	return output;
    }
};

}}
#endif	/* __LIBTRAITS_TRAITS_PARSER_HPP__ */
