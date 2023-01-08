#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

extern void init_zkelf(py::module &);
extern void init_zklog(py::module &);
extern void init_zkprocess(py::module &);

namespace zk {
PYBIND11_MODULE(pyzkinject, m) {
    m.doc() = "zkinject bindings for python";

    init_zkelf(m);
    init_zklog(m);
    init_zkprocess(m);
}
}  // namespace zk
