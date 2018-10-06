#ifndef ITER_AND_INDEX_WRAPPER_HPP
#define ITER_AND_INDEX_WRAPPER_HPP

namespace detail {

    template <typename Container>
class iter_and_index_wrapper {
public:

	template <typename iterator_base>
	class iterator {
	public:

		using value = std::pair<typename iterator_base::value_type, int>;
		using reference = value&;
		using pointer = value*;
		using const_ref = const value&;

		iterator(iterator_base base, int index) :
			member{ *base, index },
			iter{ base }
		{}

		const_ref operator*() const {
			return member;
		}

		reference operator*() {
			return member;
		}

		iterator& operator++() {
			++iter;
			member.first = *iter;
			++member.second;
			return *this;
		}

		bool operator==(const iterator& rhs) const {
			return member == rhs.member && iter == rhs.iter;
		}

		bool operator!=(const iterator& rhs) const {
			return !(*this == rhs);
		}

	private:
		value member;
		iterator_base iter;
	};

	using container_t = typename std::decay<Container>::type;
	using iterator_t = iterator<typename container_t::iterator>;

	iter_and_index_wrapper(Container& base) :
		base{ &base }
	{}

	iterator_t begin() const {
		return { base->begin(), 0 };
	}

	iterator_t end() const {
		return { base->end(), static_cast<int>(base->size()) };
	}

private:
	container_t* base;
};

}

#endif