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
    return mln::ndbuffer_image::from_buffer(
        (std::byte*) array.data(),
	mln::sample_type_id::FLOAT,
	array.ndim(), 
	sizes.data()
    );
}

std::vector<int> get_strides(mln::ndbuffer_image& buff)
{
    std::vector<int> res;
    for (int i = 0; i < buff.pdim(); ++i)
        res.push_back(buff.byte_stride(i));

    for (int i = 0; i < buff.pdim(); ++i)
    {
        for (int j = i + 1; j < buff.pdim(); ++j)
        {
            res[i] *= buff.size(j);
	}
	for (int j = i - 1; j >= 0; --j)
	{
            res[i] /= buff.size(j);
        }
    }
    return res;
}

py::array_t<float> buffer_to_array(mln::ndbuffer_image buff)
{
    auto vec_size = std::vector<size_t>();
    for (int i = 0; i < buff.pdim(); i++)
    {
        vec_size.push_back(buff.size(i));
    }
    return py::array{
       	py::buffer_info(
	    buff.buffer(),
            sizeof(buff.sample_type()), //itemsize
            py::format_descriptor<float>::format(),
            buff.pdim(), // ndim
            vec_size, // shape
            get_strides(buff) // strides
        )
    };
}
