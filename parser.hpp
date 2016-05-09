#ifndef __LIBTRAITS_PARSER_HPP__
#define __LIBTRAITS_PARSER_HPP__

#include "libtraits/traits/parser.hpp"

namespace libtraits {

template<typename T, typename IT>
std::unique_ptr<T> parse(IT& it)
{
    return traits::parser<T>::parse(it);
}

}
#endif	/* __LIBTRAITS_PARSER_HPP__ */
