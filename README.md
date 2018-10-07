# Index Iterator

This ia a small header-only library for having providing an index for C++11's range-based for loop.

Using this library this code:

```cpp
// Basic example
int index = 0;
for (const auto& val : values) {
    // Do some operation which requires the index
    ++index;
}
```

Becomes:

```cpp
// iter_and_index example
for (const auto& iterAndIndex : iter_and_index(values)) {
    // index_and_iter is a pair of the iterator and an index variable
}
```

With C++17 this become slightly simpler:

```cpp
// iter_and_index with structured bindings
for (const auto& [iter, index] : iter_and_index(values)) {
    // Our pair is destructured into an iterator and an index
}
```

## Caviats

It seems like there are plenty of approaches to this and the library was really an experiment on writing this kind of container wrapper and iterator.

In future there are simpler ways to write this including with range views (currently available in [range-v3](https://github.com/ericniebler/range-v3)):

```cpp
for (const auto& [iter, index] : v | zip(iota(0))) {

}
```

Additionally, having done some benchmarks on [quickbench](http://quick-bench.com/qF4rZ9NKf3v9yaEyYFEWY5HinV8) I have found that the indexed-iterator performs almost as quickly as the basic example (shown at the top of this page). There is a very slight performance degredation based on the benchmarks I ran. I believe this is because the compiler is better able to optimize a raw loop as the variables haven't been indirected through a `std::pair`