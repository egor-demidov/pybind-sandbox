#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>

int add(int i, int j) {
    return i + j;
}

void process_array(pybind11::array_t<double> arr) {
    pybind11::buffer_info buf_info = arr.request(true);
    double *ptr = static_cast<double *>(buf_info.ptr);

    for (ssize_t i = 0; i < buf_info.size; ++i) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

PYBIND11_MODULE(_pybind_sandbox, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
    m.def("process_array", &process_array, "Process a NumPy array");
}