#pragma once

#include <vector>
#include <utility>
#include <boost/container/map.hpp>
#include <metall/metall.hpp>

template < typename T >
using alloc_t = metall::manager::allocator_type<T>;

using vec_t = std::vector<int, alloc_t<int>>;
using map_t = boost::container::map<int, vec_t, std::less<>, alloc_t<std::pair<int const, vec_t>>>;

inline constexpr char const *DATASTORE_PATH = "/tmp/test-datastore";
inline constexpr char const *OBJ_NAME = "test-map";
