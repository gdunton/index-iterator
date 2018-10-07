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

TEST_CASE("Iterator iterates and indexes correctly") {
	
	std::vector<int> values{ 1, 2, 3 };

	const auto& wrapper = iter_and_index(values);

	auto begin = wrapper.begin();
	auto end = wrapper.end();

	auto begin1 = *begin;
	REQUIRE(begin1.first == 1);
	REQUIRE(begin1.second == 0);

	++begin;
	auto begin2 = *begin;
	REQUIRE(begin2.first == 2);
	REQUIRE(begin2.second == 1);

	++begin;
	auto begin3 = *begin;
	REQUIRE(begin3.first == 3);
	REQUIRE(begin3.second == 2);

	++begin;
	REQUIRE(begin == end);
}