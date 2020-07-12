#include <pybind11/pybind11.h>
#include "func.hh"

namespace py = pybind11;

PYBIND11_MODULE(pylene, m)
{
    m.doc() = "pybind11 module example";
    m.def("add", &add, "A function which adds two numbers");
}
