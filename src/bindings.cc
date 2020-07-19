
#include "../include/pln/core/se.hpp"
#include "convert.hh"
#include <iostream>

int test()
{
    auto test = pln::se_t(mln::se::rect2d(21,21));
    auto test2 = test.get_rect();
    auto test3 = test2.is_incremental();
    if (test3)
        return 1;
    else
        return 0;
}

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "Test function for conversion functions";
    m.def("converting_twice", &converting_twice, "Convert a same array twice");
    m.def("test", &test, "big test");
}