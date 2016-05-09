#ifndef __LIBTRAITS_DRAFT_TRAITS_MODULE_HPP__
#define __LIBTRAITS_DRAFT_TRAITS_MODULE_HPP__

namespace libtraits { namespace traits {

template<typename M>
struct moduler {
    static int get_id(const M&) {return -1;}
    static const char* get_name(const M&) {return "";}
};

}}
#endif	/* __LIBTRAITS_DRAFT_TRAITS_MODULE_HPP__ */
