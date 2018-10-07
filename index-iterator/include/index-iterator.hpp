#ifndef INDEX_ITERATOR_HPP
#define INDEX_ITERATOR_HPP

#include "detail/iter_and_index_wrapper.hpp"

template <typename Container>
detail::iter_and_index_wrapper<Container> iter_and_index(Container& c) {
	return { c };
}

#endif