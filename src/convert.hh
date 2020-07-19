#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <mln/core/image/ndimage.hpp>


#include <vector>
#include <iostream>

namespace py = pybind11;

mln::ndbuffer_image array_to_buffer(py::array_t<float> array);

py::array_t<float> buffer_to_array(mln::ndbuffer_image buff);
