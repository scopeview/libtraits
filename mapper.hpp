#ifndef __LIBTRAITS_MAPPER_HPP__
#define __LIBTRAITS_MAPPER_HPP__

#include "libtraits/traits/mapper.hpp"

namespace libtraits {

template<typename TO, typename FROM, FROM from>
constexpr TO constexpr_map() {
    static_assert(std::is_enum<FROM>::value || std::is_integral<FROM>::value, "");
    static_assert(std::is_enum<TO>::value || std::is_integral<TO>::value, "");

    return traits::constexpr_mapper<FROM, from, TO>::map();
}

}
#endif	/* __LIBTRAITS_MAPPER_HPP__ */
