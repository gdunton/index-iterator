#include <catch.hpp>
#include <index-iterator.hpp>
#include <vector>

TEST_CASE("Iterator compiles with non-const containers", "[compile-test]") {
	std::vector<int> values{ 1, 2, 3, 4 };

	for (const auto& p : iter_and_index(values)) {}
	for (const auto p : iter_and_index(values)) {}
	for (auto& p : iter_and_index(values)) {}
	for (auto p : iter_and_index(values)) {}
}

TEST_CASE("Iterator compiles with const containers", "[compile-test]") {
	const std::vector<int> values{ 1, 2, 3, 4 };

	for (const auto& p : iter_and_index(values)) {}
	for (const auto p : iter_and_index(values)) {}
	for (auto& p : iter_and_index(values)) {}
	for (auto p : iter_and_index(values)) {}
}
