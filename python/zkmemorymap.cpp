#include <pybind11/pybind11.h>

#include <zkinject/zkmemorymap.hh>
#include <zkinject/zktypes.hh>

namespace py = pybind11;

void init_for_x64(py::module& zkmm) {
    py::class_<zkprocess::page_t<x64>>(zkmm, "page_x64")
        .def(py::init<x64::addr_t, x64::addr_t, std::string,
                      std::optional<std::string>>())
        .def("get_page_start_address",
             &zkprocess::page_t<x64>::get_page_start_address)
        .def("get_page_end_address",
             &zkprocess::page_t<x64>::get_page_end_address)
        .def("get_page_name", &zkprocess::page_t<x64>::get_page_name)
        .def("get_page_permissions",
             &zkprocess::page_t<x64>::get_page_permissions);

    py::class_<zkprocess::MemoryMap<x64>>(zkmm, "Zkmemorymap_x64")
        .def(py::init<pid_t>())
        .def("parse_memory_map",
             &zkprocess::MemoryMap<x64>::parse_memory_map)
        .def("get_memory_map", &zkprocess::MemoryMap<x64>::get_memory_map)
        .def("get_module_start_address",
             &zkprocess::MemoryMap<x64>::get_module_start_address)
        .def("get_module_end_address",
             &zkprocess::MemoryMap<x64>::get_module_end_address)
        .def("get_module_page",
             &zkprocess::MemoryMap<x64>::get_module_page)
        .def("get_base_page", &zkprocess::MemoryMap<x64>::get_base_page)
        .def("get_end_page", &zkprocess::MemoryMap<x64>::get_end_page)
        .def("get_base_address",
             &zkprocess::MemoryMap<x64>::get_base_address)
        .def("get_base_end_address",
             &zkprocess::MemoryMap<x64>::get_base_end_address)
        .def("get_memory_pages",
             &zkprocess::MemoryMap<x64>::get_memory_pages)
        .def("is_mapped", &zkprocess::MemoryMap<x64>::is_mapped);
}

void init_for_x86(py::module& zkmm) {
    py::class_<zkprocess::page_t<x86>>(zkmm, "page_x86")
        .def(py::init<x86::addr_t, x86::addr_t, std::string,
                      std::optional<std::string>>())
        .def("get_page_start_address",
             &zkprocess::page_t<x86>::get_page_start_address)
        .def("get_page_end_address",
             &zkprocess::page_t<x86>::get_page_end_address)
        .def("get_page_name", &zkprocess::page_t<x86>::get_page_name)
        .def("get_page_permissions",
             &zkprocess::page_t<x86>::get_page_permissions);

    py::class_<zkprocess::MemoryMap<x86>>(zkmm, "Zkmemorymap_x86")
        .def(py::init<pid_t>())
        .def("parse_memory_map",
             &zkprocess::MemoryMap<x86>::parse_memory_map)
        .def("get_memory_map", &zkprocess::MemoryMap<x86>::get_memory_map)
        .def("get_module_start_address",
             &zkprocess::MemoryMap<x86>::get_module_start_address)
        .def("get_module_end_address",
             &zkprocess::MemoryMap<x86>::get_module_end_address)
        .def("get_module_page",
             &zkprocess::MemoryMap<x86>::get_module_page)
        .def("get_base_page", &zkprocess::MemoryMap<x86>::get_base_page)
        .def("get_end_page", &zkprocess::MemoryMap<x86>::get_end_page)
        .def("get_base_address",
             &zkprocess::MemoryMap<x86>::get_base_address)
        .def("get_base_end_address",
             &zkprocess::MemoryMap<x86>::get_base_end_address)
        .def("get_memory_pages",
             &zkprocess::MemoryMap<x86>::get_memory_pages)
        .def("is_mapped", &zkprocess::MemoryMap<x86>::is_mapped);
}

void init_zkmemorymap(py::module& m) {
    auto zkmm = m.def_submodule("zkmemorymap");
    zkmm.doc() = "zkinject's memory map parser library";

    init_for_x64(zkmm);
    init_for_x86(zkmm);
}
