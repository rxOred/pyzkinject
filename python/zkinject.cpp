#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_zkelf(py::module &);
void init_zklog(py::module &);
void init_zkmemorymap(py::module &);
void init_zkprocess(py::module &);
void init_zkptrace(py::module &);

namespace zk {
	PYBIND11_MODULE(zkinject, m) {
        m.doc() = "zkinject bindings for python";
        
        init_zkelf(m);
        init_zklog(m);
        init_zkmemorymap(m);
        init_zkprocess(m);
        init_zkptrace(m);
    }
}
