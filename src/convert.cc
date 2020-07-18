#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <mln/core/image/ndimage.hpp>
#include <vector>
#include <iostream>

namespace py = pybind11;

mln::ndbuffer_image array_to_buffer(py::array_t<float> array)
{
    auto sizes = std::vector<int>();
    for (int i = 0; i < array.ndim(); i++)
    {
      sizes.push_back(array.shape(i));
    }
    return mln::ndbuffer_image::from_buffer((std::byte*) array.data(), mln::sample_type_id::FLOAT
    ,array.ndim(), sizes.data());
}
py::array_t<float> buffer_to_array(mln::ndbuffer_image buff)
{
    auto vec_size = std::vector<size_t>();
    for (int i = 0; i < buff.pdim(); i++)
    {
        vec_size.push_back(buff.size(i));
    }
     return py::array_t<float>(
        	py::buffer_info(
	            buff.buffer(),
		       sizeof(buff.sample_type()), //itemsize
		       py::format_descriptor<float>::format(),
		       buff.pdim(), // ndim
		       vec_size, // shape
		       std::nullptr // strides
            );
}