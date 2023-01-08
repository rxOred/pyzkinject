#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <zkinject/zkelf.hh>

namespace py = pybind11;

void init_zkelf(py::module& m) {
    auto zkelf = m.def_submodule("zkelf");
    zkelf.doc() = "zkinject's elf parser library";
    py::enum_<zkelf::ei_class>(zkelf, "ei_class")
        .value("ELFCLASSNONE", zkelf::ei_class::ELFCLASSNONE)
        .value("ELFCLASS32", zkelf::ei_class::ELFCLASS32)
        .value("ELFCLASS64", zkelf::ei_class::ELFCLASS64)
        .export_values();

    py::enum_<zkelf::ei_data>(zkelf, "ei_data")
        .value("ELFDATANONE", zkelf::ei_data::ELFDATANONE)
        .value("ELFDATA2LSB", zkelf::ei_data::ELFDATA2LSB)
        .value("ELFDATA2MSB", zkelf::ei_data::ELFDATA2MSB)
        .export_values();

    py::enum_<zkelf::ei_osabi>(zkelf, "ei_osabi")
        .value("ELFOSABI_NONE", zkelf::ei_osabi::ELFOSABI_NONE)
        .value("ELFOSABI_SYSV", zkelf::ei_osabi::ELFOSABI_SYSV)
        .value("ELFOSABI_HPUX", zkelf::ei_osabi::ELFOSABI_HPUX)
        .value("ELFOSABI_NETBSD", zkelf::ei_osabi::ELFOSABI_NETBSD)
        .value("ELFOSABI_GNU", zkelf::ei_osabi::ELFOSABI_GNU)
        .value("ELFOSABI_LINUX", zkelf::ei_osabi::ELFOSABI_LINUX)
        .value("ELFOSABI_SOLARIS", zkelf::ei_osabi::ELFOSABI_SOLARIS)
        .value("ELFOSABI_AIX", zkelf::ei_osabi::ELFOSABI_AIX)
        .value("ELFOSABI_IRIX", zkelf::ei_osabi::ELFOSABI_IRIX)
        .value("ELFOSABI_FREEBSD", zkelf::ei_osabi::ELFOSABI_FREEBSD)
        .value("ELFOSABI_TRU64", zkelf::ei_osabi::ELFOSABI_TRU64)
        .value("ELFOSABI_MODESTO", zkelf::ei_osabi::ELFOSABI_MODESTO)
        .value("ELFOSABI_OPENBSD", zkelf::ei_osabi::ELFOSABI_OPENBSD)
        .value("ELFOSABI_ARM_AEABI", zkelf::ei_osabi::ELFOSABI_ARM_AEABI)
        .value("ELFOSABI_ARM", zkelf::ei_osabi::ELFOSABI_ARM)
        .value("ELFOSABI_STANDALONE", zkelf::ei_osabi::ELFOSABI_STANDALONE)
        .export_values();

    py::enum_<zkelf::e_ident>(zkelf, "e_ident")
        .value("EI_MAG0", zkelf::e_ident::EI_MAG0)
        .value("EI_MAG1", zkelf::e_ident::EI_MAG1)
        .value("EI_MAG2", zkelf::e_ident::EI_MAG2)
        .value("EI_MAG3", zkelf::e_ident::EI_MAG3)
        .value("EI_CLASS", zkelf::e_ident::EI_CLASS)
        .value("EI_DATA", zkelf::e_ident::EI_CLASS)
        .value("EI_VERSION", zkelf::e_ident::EI_VERSION)
        .value("EI_OSABI", zkelf::e_ident::EI_OSABI)
        .value("EI_ABIVERSION", zkelf::e_ident::EI_ABIVERSION)
        .value("EI_PAD", zkelf::e_ident::EI_PAD)
        .export_values();

    py::enum_<zkelf::e_type>(zkelf, "e_type")
        .value("ET_NONE", zkelf::e_type::ET_NONE)
        .value("ET_REL", zkelf::e_type::ET_REL)
        .value("ET_EXEC", zkelf::e_type::ET_EXEC)
        .value("ET_DYN", zkelf::e_type::ET_DYN)
        .value("ET_CORE", zkelf::e_type::ET_CORE)
        .value("ET_NUM", zkelf::e_type::ET_NUM)
        .value("ET_LOOS", zkelf::e_type::ET_LOOS)
        .value("ET_HIOS", zkelf::e_type::ET_HIOS)
        .value("ET_LOPROC", zkelf::e_type::ET_LOPROC)
        .value("ET_HIPROC", zkelf::e_type::ET_HIPROC)
        .export_values();

    py::enum_<zkelf::e_machine>(zkelf, "e_machine")
        .value("EM_NONE", zkelf::e_machine::EM_NONE)
        .value("EM_M32", zkelf::e_machine::EM_M32)
        .value("EM_SPARC", zkelf::e_machine::EM_SPARC)
        .value("EM_386", zkelf::e_machine::EM_386)
        .value("EM_68k", zkelf::e_machine::EM_68K)
        .value("EM_88K", zkelf::e_machine::EM_88K)
        .value("EM_860", zkelf::e_machine::EM_860)
        .value("EM_MIPS", zkelf::e_machine::EM_MIPS)
        .value("EM_PARISC", zkelf::e_machine::EM_PARISC)
        .value("EM_SPARC32PLUS", zkelf::e_machine::EM_SPARC32PLUS)
        .value("EM_PPC", zkelf::e_machine::EM_PPC)
        .value("EM_PPC64", zkelf::e_machine::EM_PPC64)
        .value("EM_S390", zkelf::e_machine::EM_S390)
        .value("EM_ARM", zkelf::e_machine::EM_ARM)
        .value("EM_SPARCV9", zkelf::e_machine::EM_SPARCV9)
        .value("EM_IA_64", zkelf::e_machine::EM_IA_64)
        .value("EM_X86_64", zkelf::e_machine::EM_X86_64)
        .value("EM_AVR", zkelf::e_machine::EM_AVR)
        .value("EM_BPF", zkelf::e_machine::EM_BPF)
        .export_values();

    py::enum_<zkelf::e_version>(zkelf, "e_version")
        .value("EV_CURRENT", zkelf::e_version::EV_CURRENT)
        .value("EV_NONE", zkelf::e_version::EV_NONE)
        .value("EV_NUM", zkelf::e_version::EV_NUM)
        .export_values();

    py::class_<zkelf::ehdr_t<x64>>(zkelf, "ehdr_x64")
        .def_property_readonly("e_ident[]",
                               [](py::object& obj) {
                                   auto& e =
                                       obj.cast<zkelf::ehdr_t<x64>&>();
                                   return py::array{16, e.e_ident, obj};
                               })
        .def_readwrite("elf_type", &zkelf::ehdr_t<x64>::elf_type)
        .def_readwrite("elf_machine", &zkelf::ehdr_t<x64>::elf_machine)
        .def_readwrite("elf_entry", &zkelf::ehdr_t<x64>::elf_entry);
}
