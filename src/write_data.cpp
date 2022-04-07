#include "../include/common.hpp"

#include <metall/metall.hpp>
#include <iostream>
#include <filesystem>

auto main() -> int {
    if (!std::filesystem::exists(DATASTORE_PATH)) {
        metall::manager{metall::create_only, DATASTORE_PATH};
    }

    metall::manager mng{metall::open_only, DATASTORE_PATH};
    auto *p = mng.template find_or_construct<map_t>(OBJ_NAME)(mng.get_allocator());

    // insert some random data
    vec_t v{ mng.get_allocator() };
    v.push_back(1);
    v.push_back(3);

    p->emplace(5, std::move(v));

    vec_t v2{ mng.get_allocator() };
    v2.push_back(99);
    v2.push_back(123);

    p->emplace(42, std::move(v2));
}
