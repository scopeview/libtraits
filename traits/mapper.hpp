#ifndef __LIBTRAITS_TRAITS_MAPPER_HPP__
#define __LIBTRAITS_TRAITS_MAPPER_HPP__

namespace libtraits { namespace traits {

template<typename FROM, FROM from, typename TO>
struct value_mapper;

#define DEFINE_VALUE_MAPPER(FROM, from, TO, to)	\
    template<>					\
    struct value_mapper<FROM, from, TO> {	\
	static constexpr TO to_value = to;	\
    };						\
/***/

////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////
template<typename FROM, FROM from, typename TO>
struct constexpr_mapper {
    static constexpr TO map() {
	return value_mapper<FROM, from, TO>::to_value;
    }
};


}}
#endif	/* __LIBTRAITS_TRAITS_MAPPER_HPP__ */
