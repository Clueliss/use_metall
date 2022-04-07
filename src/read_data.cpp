#include "../include/common.hpp"

#include <cstdio>
#include <cstdlib>
#include <metall/metall.hpp>

#define FMT_HEADER_ONLY
#include <fmt/format.h>

auto main() -> int {
    metall::manager const mng{metall::open_read_only, DATASTORE_PATH};

    auto const [p, _count] = mng.template find<map_t>(OBJ_NAME);

    if (p == nullptr) {
        fmt::print(stderr, "Error: object was not previously allocated\n");
        return EXIT_FAILURE;
    }

    for (auto const &[ix, value]: *p) {
        fmt::print("{}: [{}]\n", ix, fmt::join(value, ", "));
    }
}
