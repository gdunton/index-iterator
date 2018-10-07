#ifndef ITER_AND_INDEX_WRAPPER_HPP
#define ITER_AND_INDEX_WRAPPER_HPP

namespace detail {

	template <typename>
	class iterator;

	//---------------------------------------------------------
	// Container wrapper
	//---------------------------------------------------------
    template <typename Container>
	class iter_and_index_wrapper {
	private:
		const Container * base;

	public:

		using iterator_t = iterator<decltype(base->begin())>;

		iter_and_index_wrapper(Container& base) :
			base{ &base }
		{}

		iterator_t begin() const {
			return { base->begin(), 0 };
		}

		iterator_t end() const {
			return { base->end(), static_cast<int>(base->size()) };
		}
	};

	//---------------------------------------------------------
	// Iterator definition
	//---------------------------------------------------------
	template <typename iterator_base>
	class iterator {
	public:

		using value = std::pair<typename iterator_base::value_type, int>;
		using reference = std::pair<typename iterator_base::reference, int>;
		using pointer = std::pair<typename iterator_base::pointer, int>;
		using const_ref = std::pair<const typename iterator_base::reference, int>;

		iterator(iterator_base base, int index) :
			iter{ base },
			index{ index }
		{}

		const_ref operator*() const {
			return { *iter, index };
		}

		reference operator*() {
			return { *iter, index };
		}

		iterator& operator++() {
			++iter;
			++index;
			return *this;
		}

		bool operator==(const iterator& rhs) const {
			return iter == rhs.iter && index == rhs.index;
		}

		bool operator!=(const iterator& rhs) const {
			return !(*this == rhs);
		}

	private:
		iterator_base iter;
		int index;
	};

}

#endif