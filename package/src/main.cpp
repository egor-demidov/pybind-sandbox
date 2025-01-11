#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <iostream>

int add(int i, int j) {
    return i + j;
}

void process_array(pybind11::array_t<double> arr) {
    pybind11::buffer_info buf_info = arr.request(true);
    double *ptr = static_cast<double *>(buf_info.ptr);

    for (size_t i = 0; i < buf_info.size; ++i) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

class ExampleClass {
public:
    ExampleClass(int a, int b)
        : a_{a}
        , b_{b}
    {}

    int get_secret() const {
        return 7*a_ - b_;
    }

private:
    const int a_, b_;
};

PYBIND11_MODULE(_pybind_sandbox, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function that adds two numbers");
    m.def("process_array", &process_array, "Process a NumPy array");

    pybind11::class_<ExampleClass>(m, "ExampleClass")
        .def(pybind11::init<int, int>())
        .def("get_secret", &ExampleClass::get_secret);
}
