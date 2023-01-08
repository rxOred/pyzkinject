#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <zkinject/zkprocess.hh>

namespace py = pybind11;

extern void init_zkmemorymap(py::module& m);
// extern void init_zkptrace(py::module& m);

void init_zkprocess(py::module& m) {
    auto process = m.def_submodule("zkprocess");

    // TODO
    // zkprocess stuff here

    init_zkmemorymap(process);
    // init_zkptrace(process);
}