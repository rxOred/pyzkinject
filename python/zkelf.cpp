#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <zkinject/zkelf.hh>
#include <zkinject/zktypes.hh>

namespace py = pybind11;

void init_ehdr_for_x64(py::module& m) {
    py::class_<zkelf::ehdr_t<x64>>(m, "ehdr_x64")
        .def_property_readonly("e_ident[]",
                               [](py::object& obj) {
                                   auto& e =
                                       obj.cast<zkelf::ehdr_t<x64>&>();
                                   return py::array{16, e.e_ident, obj};
                               })
        .def_readwrite("elf_type", &zkelf::ehdr_t<x64>::elf_type)
        .def_readwrite("elf_machine", &zkelf::ehdr_t<x64>::elf_machine)
        .def_readwrite("elf_entry", &zkelf::ehdr_t<x64>::elf_entry)
        .def_readwrite("elf_phoff", &zkelf::ehdr_t<x64>::elf_phoff)
        .def_readwrite("elf_shoff", &zkelf::ehdr_t<x64>::elf_shoff)
        .def_readwrite("elf_flags", &zkelf::ehdr_t<x64>::elf_flags)
        .def_readwrite("elf_ehsize", &zkelf::ehdr_t<x64>::elf_ehsize)
        .def_readwrite("elf_phentsize", &zkelf::ehdr_t<x64>::elf_phentsize)
        .def_readwrite("elf_phnum", &zkelf::ehdr_t<x64>::elf_phnum)
        .def_readwrite("elf_shentsize", &zkelf::ehdr_t<x64>::elf_shentsize)
        .def_readwrite("elf_shnum", &zkelf::ehdr_t<x64>::elf_shnum)
        .def_readwrite("elf_shstrndx", &zkelf::ehdr_t<x64>::elf_shstrndx)
        .doc() = "elf header for x64";
}

void init_ehdr_for_x86(py::module& m) {
    py::class_<zkelf::ehdr_t<x86>>(m, "ehdr_x86")
        .def_property_readonly("e_ident[]",
                               [](py::object& obj) {
                                   auto& e =
                                       obj.cast<zkelf::ehdr_t<x86>&>();
                                   return py::array{16, e.e_ident, obj};
                               })
        .def_readwrite("elf_type", &zkelf::ehdr_t<x86>::elf_type)
        .def_readwrite("elf_machine", &zkelf::ehdr_t<x86>::elf_machine)
        .def_readwrite("elf_entry", &zkelf::ehdr_t<x86>::elf_entry)
        .def_readwrite("elf_phoff", &zkelf::ehdr_t<x86>::elf_phoff)
        .def_readwrite("elf_shoff", &zkelf::ehdr_t<x86>::elf_shoff)
        .def_readwrite("elf_flags", &zkelf::ehdr_t<x86>::elf_flags)
        .def_readwrite("elf_ehsize", &zkelf::ehdr_t<x86>::elf_ehsize)
        .def_readwrite("elf_phentsize", &zkelf::ehdr_t<x86>::elf_phentsize)
        .def_readwrite("elf_phnum", &zkelf::ehdr_t<x86>::elf_phnum)
        .def_readwrite("elf_shentsize", &zkelf::ehdr_t<x86>::elf_shentsize)
        .def_readwrite("elf_shnum", &zkelf::ehdr_t<x86>::elf_shnum)
        .def_readwrite("elf_shstrndx", &zkelf::ehdr_t<x86>::elf_shstrndx)
        .doc() = "elf header for x86";
}

void init_phdr_for_x64(py::module& m) {
    py::class_<zkelf::phdr_t<x64>>(m, "phdr_x64")
        .def_readwrite("ph_type", &zkelf::phdr_t<x64>::ph_type)
        .def_readwrite("ph_flags", &zkelf::phdr_t<x64>::ph_flags)
        .def_readwrite("ph_offset", &zkelf::phdr_t<x64>::ph_offset)
        .def_readwrite("ph_vaddr", &zkelf::phdr_t<x64>::ph_vaddr)
        .def_readwrite("ph_paddr", &zkelf::phdr_t<x64>::ph_paddr)
        .def_readwrite("ph_filesz", &zkelf::phdr_t<x64>::ph_filesz)
        .def_readwrite("ph_memsz", &zkelf::phdr_t<x64>::ph_memsz)
        .def_readwrite("ph_align", &zkelf::phdr_t<x64>::ph_align)
        .doc() = "program header table entry for x64";
}

void init_phdr_for_x86(py::module& m) {
    py::class_<zkelf::phdr_t<x86>>(m, "phdr_x86")
        .def_readwrite("ph_type", &zkelf::phdr_t<x86>::ph_type)
        .def_readwrite("ph_flags", &zkelf::phdr_t<x86>::ph_flags)
        .def_readwrite("ph_offset", &zkelf::phdr_t<x86>::ph_offset)
        .def_readwrite("ph_vaddr", &zkelf::phdr_t<x86>::ph_vaddr)
        .def_readwrite("ph_paddr", &zkelf::phdr_t<x86>::ph_paddr)
        .def_readwrite("ph_filesz", &zkelf::phdr_t<x86>::ph_filesz)
        .def_readwrite("ph_memsz", &zkelf::phdr_t<x86>::ph_memsz)
        .def_readwrite("ph_align", &zkelf::phdr_t<x86>::ph_align)
        .doc() = "program header table entry for x86";
}

void init_shdr_for_x64(py::module& m) {
    py::class_<zkelf::shdr_t<x64>>(m, "shdr_x64")
        .def_readwrite("sh_name", &zkelf::shdr_t<x64>::sh_name)
        .def_readwrite("sh_type", &zkelf::shdr_t<x64>::sh_type)
        .def_readwrite("sh_flags", &zkelf::shdr_t<x64>::sh_flags)
        .def_readwrite("sh_addr", &zkelf::shdr_t<x64>::sh_addr)
        .def_readwrite("sh_offset", &zkelf::shdr_t<x64>::sh_offset)
        .def_readwrite("sh_size", &zkelf::shdr_t<x64>::sh_size)
        .def_readwrite("sh_link", &zkelf::shdr_t<x64>::sh_link)
        .def_readwrite("sh_info", &zkelf::shdr_t<x64>::sh_info)
        .def_readwrite("sh_addralign", &zkelf::shdr_t<x64>::sh_addralign)
        .def_readwrite("sh_entsize", &zkelf::shdr_t<x64>::sh_entsize)
        .doc() = "section header table entry for x64";
}

void init_shdr_for_x86(py::module& m) {
    py::class_<zkelf::shdr_t<x86>>(m, "shdr_x86")
        .def_readwrite("sh_name", &zkelf::shdr_t<x86>::sh_name)
        .def_readwrite("sh_type", &zkelf::shdr_t<x86>::sh_type)
        .def_readwrite("sh_flags", &zkelf::shdr_t<x86>::sh_flags)
        .def_readwrite("sh_addr", &zkelf::shdr_t<x86>::sh_addr)
        .def_readwrite("sh_offset", &zkelf::shdr_t<x86>::sh_offset)
        .def_readwrite("sh_size", &zkelf::shdr_t<x86>::sh_size)
        .def_readwrite("sh_link", &zkelf::shdr_t<x86>::sh_link)
        .def_readwrite("sh_info", &zkelf::shdr_t<x86>::sh_info)
        .def_readwrite("sh_addralign", &zkelf::shdr_t<x86>::sh_addralign)
        .def_readwrite("sh_entsize", &zkelf::shdr_t<x86>::sh_entsize)
        .doc() = "section header table entry for x86";
}

void init_symtab_for_x64(py::module& m) {
    py::class_<zkelf::symtab_t<x64>>(m, "symtab_x64")
        .def_readwrite("st_name", &zkelf::symtab_t<x64>::st_name)
        .def_readwrite("st_info", &zkelf::symtab_t<x64>::st_info)
        .def_readwrite("st_other", &zkelf::symtab_t<x64>::st_other)
        .def_readwrite("st_shndx", &zkelf::symtab_t<x64>::st_shndx)
        .def_readwrite("st_value", &zkelf::symtab_t<x64>::st_value)
        .def_readwrite("st_size", &zkelf::symtab_t<x64>::st_size)
        .doc() = "symbol table entry for x64";
}

void init_symtab_for_x86(py::module& m) {
    py::class_<zkelf::symtab_t<x86>>(m, "symtab_x86")
        .def_readwrite("st_name", &zkelf::symtab_t<x86>::st_name)
        .def_readwrite("st_value", &zkelf::symtab_t<x86>::st_value)
        .def_readwrite("st_size", &zkelf::symtab_t<x86>::st_size)
        .def_readwrite("st_info", &zkelf::symtab_t<x86>::st_info)
        .def_readwrite("st_other", &zkelf::symtab_t<x86>::st_other)
        .def_readwrite("st_shndx", &zkelf::symtab_t<x86>::st_shndx)
        .doc() = "symbol table entry for x86";
}

void init_relocation_for_x64(py::module& m) {
    py::class_<zkelf::relocation_t<x64, false>>(m, "rel_x64")
        .def_readwrite("r_offset",
                       &zkelf::relocation_t<x64, false>::r_offset)
        .def_readwrite("r_info", &zkelf::relocation_t<x64, false>::r_info)
        .doc() = "relocation table entry without the addend";

    py::class_<zkelf::relocation_t<x64, true>>(m, "rela_x64")
        .def_readwrite("r_offset",
                       &zkelf::relocation_t<x64, true>::r_offset)
        .def_readwrite("r_info", &zkelf::relocation_t<x64, true>::r_info)
        .def_readwrite("r_addend",
                       &zkelf::relocation_t<x64, true>::r_addend)
        .doc() = "relocation table entry with the addend";
}

void init_relocation_for_x86(py::module& m) {
    py::class_<zkelf::relocation_t<x86, false>>(m, "rel_x86")
        .def_readwrite("r_offset",
                       &zkelf::relocation_t<x86, false>::r_offset)
        .def_readwrite("r_info", &zkelf::relocation_t<x86, false>::r_info)
        .doc() = "relocation table entry without the addend";

    py::class_<zkelf::relocation_t<x86, true>>(m, "rela_x86")
        .def_readwrite("r_offset",
                       &zkelf::relocation_t<x86, true>::r_offset)
        .def_readwrite("r_info", &zkelf::relocation_t<x86, true>::r_info)
        .def_readwrite("r_addend",
                       &zkelf::relocation_t<x86, true>::r_addend)
        .doc() = "relocation table entry with the addend";
}

void init_nhdr_for_x64(py::module& m) {
    py::class_<zkelf::nhdr_t<x64>>(m, "nhdr_x64")
        .def_readwrite("n_namesz", &zkelf::nhdr_t<x64>::n_namesz)
        .def_readwrite("n_descsz", &zkelf::nhdr_t<x64>::n_descsz)
        .def_readwrite("n_type", &zkelf::nhdr_t<x64>::n_type)
        .doc() = "note section header table for x64";
}

void init_nhdr_for_x86(py::module& m) {
    py::class_<zkelf::nhdr_t<x86>>(m, "nhdr_x86")
        .def_readwrite("n_namesz", &zkelf::nhdr_t<x86>::n_namesz)
        .def_readwrite("n_descsz", &zkelf::nhdr_t<x86>::n_descsz)
        .def_readwrite("n_type", &zkelf::nhdr_t<x86>::n_type)
        .doc() = "note section header table for x86";
}

void init_dynamic_for_x64(py::module& m) {
    py::class_<zkelf::dynamic_t<x64>>(m, "dynamic_x64")
        .def_readwrite("d_tag", &zkelf::dynamic_t<x64>::d_tag)
        .def_readwrite("d_un", &zkelf::dynamic_t<x64>::d_un)
        .doc() = "dynamic section entry for x64";
}

void init_dynamic_for_x86(py::module& m) {
    py::class_<zkelf::dynamic_t<x86>>(m, "dynamic_x86")
        .def_readwrite("d_tag", &zkelf::dynamic_t<x86>::d_tag)
        .def_readwrite("d_un", &zkelf::dynamic_t<x86>::d_un)
        .doc() = "dynamic section entry for x86";
}

// TODO in elfobj, functions that return raw pointers might not work
// properly
void init_elfobj_for_x64(py::module& m) {
    py::class_<zkelf::ElfObj<x64>>(m, "Elfobj_x64")
        .def(py::init<void*, std::size_t,
                      std::variant<const char*, pid_t>>())
        .def_property_readonly("is_stripped",
                               &zkelf::ElfObj<x64>::is_stripped)
        .def_property_readonly("memory_map",
                               &zkelf::ElfObj<x64>::get_memory_map)
        .def_property_readonly("map_size",
                               &zkelf::ElfObj<x64>::get_map_size)
        .def_property_readonly("elf_source",
                               &zkelf::ElfObj<x64>::get_elf_source)
        .def_property("elf_header", &zkelf::ElfObj<x64>::get_elf_header,
                      &zkelf::ElfObj<x64>::set_elf_header)
        .def_property("program_header_table",
                      &zkelf::ElfObj<x64>::get_program_header_table,
                      &zkelf::ElfObj<x64>::set_program_header_table)
        .def_property("section_header_table",
                      &zkelf::ElfObj<x64>::get_section_header_table,
                      &zkelf::ElfObj<x64>::set_section_header_string_table)
        .def_property("string_table",
                      &zkelf::ElfObj<x64>::get_string_table,
                      &zkelf::ElfObj<x64>::set_string_table)
        .def_property("section_header_string_table",
                      &zkelf::ElfObj<x64>::get_section_header_string_table,
                      &zkelf::ElfObj<x64>::set_section_header_string_table)
        .def_property("dynamic_string_table",
                      &zkelf::ElfObj<x64>::get_dynamic_string_table,
                      &zkelf::ElfObj<x64>::set_dynamic_string_table)
        .def_property("symbol_table",
                      &zkelf::ElfObj<x64>::get_symbol_table,
                      &zkelf::ElfObj<x64>::set_symbol_table)
        .def_property("dynamic_symbol_table",
                      &zkelf::ElfObj<x64>::get_dynamic_symbol_table,
                      &zkelf::ElfObj<x64>::set_dynamic_symbol_table)
        .def_property("dynamic_section",
                      &zkelf::ElfObj<x64>::get_dynamic_section,
                      &zkelf::ElfObj<x64>::set_dynamic_section)
        .def_property("note_section",
                      &zkelf::ElfObj<x64>::get_note_section,
                      &zkelf::ElfObj<x64>::set_note_section)
        .doc() = "internal class that represents an elf object";
}

void init_elfobj_for_x86(py::module& m) {
    py::class_<zkelf::ElfObj<x86>>(m, "Elfobj_x86")
        .def(py::init<void*, std::size_t,
                      std::variant<const char*, pid_t>>())
        .def_property_readonly("is_stripped",
                               &zkelf::ElfObj<x86>::is_stripped)
        .def_property_readonly("memory_map",
                               &zkelf::ElfObj<x86>::get_memory_map)
        .def_property_readonly("map_size",
                               &zkelf::ElfObj<x86>::get_map_size)
        .def_property_readonly("elf_source",
                               &zkelf::ElfObj<x86>::get_elf_source)
        .def_property("elf_header", &zkelf::ElfObj<x86>::get_elf_header,
                      &zkelf::ElfObj<x86>::set_elf_header)
        .def_property("program_header_table",
                      &zkelf::ElfObj<x86>::get_program_header_table,
                      &zkelf::ElfObj<x86>::set_program_header_table)
        .def_property("section_header_table",
                      &zkelf::ElfObj<x86>::get_section_header_table,
                      &zkelf::ElfObj<x86>::set_section_header_string_table)
        .def_property("string_table",
                      &zkelf::ElfObj<x86>::get_string_table,
                      &zkelf::ElfObj<x86>::set_string_table)
        .def_property("section_header_string_table",
                      &zkelf::ElfObj<x86>::get_section_header_string_table,
                      &zkelf::ElfObj<x86>::set_section_header_string_table)
        .def_property("dynamic_string_table",
                      &zkelf::ElfObj<x86>::get_dynamic_string_table,
                      &zkelf::ElfObj<x86>::set_dynamic_string_table)
        .def_property("symbol_table",
                      &zkelf::ElfObj<x86>::get_symbol_table,
                      &zkelf::ElfObj<x86>::set_symbol_table)
        .def_property("dynamic_symbol_table",
                      &zkelf::ElfObj<x86>::get_dynamic_symbol_table,
                      &zkelf::ElfObj<x86>::set_dynamic_symbol_table)
        .def_property("dynamic_section",
                      &zkelf::ElfObj<x86>::get_dynamic_section,
                      &zkelf::ElfObj<x86>::set_dynamic_section)
        .def_property("note_section",
                      &zkelf::ElfObj<x86>::get_note_section,
                      &zkelf::ElfObj<x86>::set_note_section)
        .doc() = "internal class that represents an elf object";
}

void init_zkelf_for_x64(py::module& m) {
    py::class_<zkelf::ZkElf>(m, "Zkelf")
        .def(py::init(
            [](zkelf::ElfObj<x64> elf, std::optional<zklog::ZkLog*> log) {
                return std::make_unique<zkelf::ZkElf>(
                    elf, zkelf::elf_read_only{}, log);
            }))
        .def(py::init(
            [](zkelf::ElfObj<x86> elf, std::optional<zklog::ZkLog*> log) {
                return std::make_unique<zkelf::ZkElf>(
                    elf, zkelf::elf_read_only{}, log);
            }))
        .def(py::init([](zkelf::ElfObj<x64> elf, zkelf::elf_read_write op,
                         std::optional<zklog::ZkLog*> log) {
            return std::make_unique<zkelf::ZkElf>(elf, op, log);
        }))
        .def(py::init([](zkelf::ElfObj<x86> elf, zkelf::elf_read_write op,
                         std::optional<zklog::ZkLog*> log) {
            return std::make_unique<zkelf::ZkElf>(elf, op, log);
        }))
        .def("get_memory_map", &zkelf::ZkElf::get_memory_map)
        .def("get_map_size", &zkelf::ZkElf::get_map_size)
        .def("is_stripped", &zkelf::ZkElf::is_stripped)
        .def("get_elf_class", &zkelf::ZkElf::get_elf_class)
        .def("get_elf_encoding", &zkelf::ZkElf::get_elf_encoding)
        .def("get_elf_osabi", &zkelf::ZkElf::get_elf_osabi)
        .def("get_elf_type", &zkelf::ZkElf::get_elf_type)
        .def("get_elf_machine", &zkelf::ZkElf::get_elf_machine)
        .def("get_elf_version", &zkelf::ZkElf::get_elf_version)
        .def("get_elf_entry_point", &zkelf::ZkElf::get_elf_entry_point)
        .def("get_elf_phdr_offset", &zkelf::ZkElf::get_elf_phdr_offset)
        .def("get_elf_shdr_offset", &zkelf::ZkElf::get_elf_shdr_offset)
        .def("get_elf_flags", &zkelf::ZkElf::get_elf_flags)
        .def("get_elf_header_size", &zkelf::ZkElf::get_elf_header_size)
        .def("get_elf_phdr_entry_size",
             &zkelf::ZkElf::get_elf_phdr_entry_size)
        .def("get_elf_phdr_entry_count",
             &zkelf::ZkElf::get_elf_phdr_entry_count)
        .def("get_elf_shdr_entry_size",
             &zkelf::ZkElf::get_elf_shdr_entry_size)
        .def("get_elf_shdr_entry_count",
             &zkelf::ZkElf::get_elf_shdr_entry_count)
        .def("get_elf_shdr_string_table_index",
             &zkelf::ZkElf::get_elf_shdr_string_table_index)
        .def("get_section_name_index",
             &zkelf::ZkElf::get_section_name_index)
        .def("get_section_type", &zkelf::ZkElf::get_section_type)
        .def("get_section_flags", &zkelf::ZkElf::get_section_flags)
        .def("get_section_address", &zkelf::ZkElf::get_section_address)
        .def("get_section_offset", &zkelf::ZkElf::get_section_offset)
        .def("get_section_size", &zkelf::ZkElf::get_section_size)
        .def("get_section_address_alignment",
             &zkelf::ZkElf::get_section_address_alignment)
        .def("get_section_entry_size",
             &zkelf::ZkElf::get_section_entry_size)
        .def("get_section_link", &zkelf::ZkElf::get_section_link)
        .def("get_section_info", &zkelf::ZkElf::get_section_info)
        .def("get_segment_type", &zkelf::ZkElf::get_segment_type)
        .def("get_segment_offset", &zkelf::ZkElf::get_segment_offset)
        .def("get_segment_vaddress", &zkelf::ZkElf::get_segment_vaddress)
        .def("get_segment_paddress", &zkelf::ZkElf::get_segment_paddress)
        .def("get_segment_flags", &zkelf::ZkElf::get_segment_flags)
        .def("get_segment_file_size", &zkelf::ZkElf::get_segment_file_size)
        .def("get_segment_memory_size",
             &zkelf::ZkElf::get_segment_memory_size)
        .def("get_segment_address_alignment",
             &zkelf::ZkElf::get_segment_address_alignment)
        .def("get_section_index_by_name",
             &zkelf::ZkElf::get_section_index_by_name)
        .def("get_section_index_by_attr",
             &zkelf::ZkElf::get_section_index_by_attr)
        .def("get_segment_index_by_attr",
             &zkelf::ZkElf::get_segment_index_by_attr)
        .def("get_symbol_index_by_name",
             &zkelf::ZkElf::get_symbol_index_by_name)
        .def("get_dynamic_symbol_index_by_name",
             &zkelf::ZkElf::get_dynamic_symbol_index_by_name)
        .def("set_stripped", &zkelf::ZkElf::set_stripped)
        .def("set_elf_type", &zkelf::ZkElf::set_elf_type)
        .def("set_elf_machine", &zkelf::ZkElf::set_elf_machine)
        .def("set_elf_version", &zkelf::ZkElf::set_elf_version)
        .def("set_elf_flags", &zkelf::ZkElf::set_elf_flags)
        .def("set_elf_entry_point",
             &zkelf::ZkElf::set_elf_entry_point<x64::addr_t>)
        .def("set_elf_entry_point",
             &zkelf::ZkElf::set_elf_entry_point<x86::addr_t>)
        .def("set_elf_phdr_offset",
             &zkelf::ZkElf::set_elf_phdr_offset<x64::off_t>)
        .def("set_elf_phdr_offset",
             &zkelf::ZkElf::set_elf_phdr_offset<x86::off_t>)
        .def("set_elf_shdr_offset",
             &zkelf::ZkElf::set_elf_shdr_offset<x64::off_t>)
        .def("set_elf_shdr_offset",
             &zkelf::ZkElf::set_elf_shdr_offset<x86::off_t>)
        .def("set_elf_phdr_entry_count",
             &zkelf::ZkElf::set_elf_phdr_entry_count)
        .def("set_elf_shdr_entry_count",
             &zkelf::ZkElf::set_elf_shdr_entry_count)
        .def("set_elf_shdr_string_table_index",
             &zkelf::ZkElf::set_elf_shdr_string_table_index)
        .def("set_elf_header", &zkelf::ZkElf::set_elf_header)
        .def("set_section_name_index",
             &zkelf::ZkElf::set_section_name_index)
        .def("set_section_type", &zkelf::ZkElf::set_section_type)
        .def("set_section_address",
             &zkelf::ZkElf::set_section_address<x64::addr_t>)
        .def("set_section_address",
             &zkelf::ZkElf::set_section_address<x86::addr_t>)
        .def("set_section_offset", &zkelf::ZkElf::set_section_offset<x64::off_t>)
        .def("set_section_offset", &zkelf::ZkElf::set_section_offset<x86::off_t>)
        .def("set_section_size", &zkelf::ZkElf::set_section_size<x64::addr_t>)
        .def("set_section_size", &zkelf::ZkElf::set_section_size<x86::addr_t>)
        .def("set_section_address_alignment",
             &zkelf::ZkElf::set_section_address_alignment<x64::addr_t>)
        .def("set_section_address_alignment",
             &zkelf::ZkElf::set_section_address_alignment<x86::addr_t>)
        .def("set_section_link", &zkelf::ZkElf::set_section_link)
        .def("set_section_info", &zkelf::ZkElf::set_section_info)
		.def("set_section_header_table", &zkelf::ZkElf::set_section_header_table<zkelf::shdr_t<x64>>)
		.def("set_section_header_table", &zkelf::ZkElf::set_section_header_table<zkelf::shdr_t<x86>>)
		// set_section_header
		.def("set_section_data", &zkelf::ZkElf::set_section_data)
		.def("set_segment_type", &zkelf::ZkElf::set_segment_type)
		.def("set_segment_offset", &zkelf::ZkElf::set_segment_offset<x64::off_t>)
		.def("set_segment_offset", &zkelf::ZkElf::set_segment_offset<x86::off_t>)
		.def("set_segment_vaddress", &zkelf::ZkElf::set_segment_vaddress<x64::addr_t>)
		.def("set_segment_vaddress", &zkelf::ZkElf::set_segment_vaddress<x86::addr_t>)
		.def("set_segment_paddress", &zkelf::ZkElf::set_segment_paddress<x64::addr_t>)
		.def("set_segment_paddress", &zkelf::ZkElf::set_segment_paddress<x86::addr_t>)
		.def("set_segment_flags", &zkelf::ZkElf::set_segment_flags)
		.def("set_segment_file_size", &zkelf::ZkElf::set_segment_file_size)
		.def("set_segment_memory_size", &zkelf::ZkElf::set_segment_alignment)
		.def("set_program_header_table", &zkelf::ZkElf::set_program_header_table<zkelf::phdr_t<x64>>)	
		.def("set_program_header_table", &zkelf::ZkElf::set_program_header_table<zkelf::phdr_t<x86>>)
		// set_program_header
		// set_segment_data
		.def("elf_read", &zkelf::ZkElf::elf_read)
		.def("elf_write", &zkelf::ZkElf::elf_write)
		.def("save_source", &zkelf::ZkElf::save_source);
}

void init_zkelf(py::module& m) {
    auto zkelf = m.def_submodule("zkelf");
    zkelf.doc() = "zkinject's elf parser library";
    py::enum_<zkelf::ei_class>(zkelf, "ei_class")
        .value("ELFCLASSNONE", zkelf::ei_class::ELFCLASSNONE)
        .value("ELFCLASS32", zkelf::ei_class::ELFCLASS32)
        .value("ELFCLASS64", zkelf::ei_class::ELFCLASS64)
        .export_values()
        .doc() = "architecture of the elf (64 or 32 bit)";

    py::enum_<zkelf::ei_data>(zkelf, "ei_data")
        .value("ELFDATANONE", zkelf::ei_data::ELFDATANONE)
        .value("ELFDATA2LSB", zkelf::ei_data::ELFDATA2LSB)
        .value("ELFDATA2MSB", zkelf::ei_data::ELFDATA2MSB)
        .export_values()
        .doc() = "data encoding of the elf";

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
        .export_values()
        .doc() = "target Application Binary Interface (ABI) of the elf";

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
        .export_values()
        .doc() = "first 16 bytes of the elf";

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
        .export_values()
        .doc() = "type of the elf";

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
        .export_values()
        .doc() = "target processor architecture of the elf";

    py::enum_<zkelf::e_version>(zkelf, "e_version")
        .value("EV_CURRENT", zkelf::e_version::EV_CURRENT)
        .value("EV_NONE", zkelf::e_version::EV_NONE)
        .value("EV_NUM", zkelf::e_version::EV_NUM)
        .export_values()
        .doc() = "version of the elf";

    init_ehdr_for_x64(zkelf);
    init_ehdr_for_x86(zkelf);

    py::enum_<zkelf::p_type>(zkelf, "p_type")
        .value("PT_NULL", zkelf::p_type::PT_NULL)
        .value("PT_LOAD", zkelf::p_type::PT_LOAD)
        .value("PT_DYNAMIC", zkelf::p_type::PT_DYNAMIC)
        .value("PT_INTERP", zkelf::p_type::PT_INTERP)
        .value("PT_NOTE", zkelf::p_type::PT_NOTE)
        .value("PT_SHLIB", zkelf::p_type::PT_SHLIB)
        .value("PT_PHDR", zkelf::p_type::PT_PHDR)
        .value("PT_LOPROC", zkelf::p_type::PT_LOPROC)
        .value("PT_HIPROC", zkelf::p_type::PT_HIPROC)
        .value("PT_GNU_STACK", zkelf::p_type::PT_GNU_STACK)
        .export_values()
        .doc() = "type of the segment";

    py::enum_<zkelf::p_flags>(zkelf, "p_flags")
        .value("execute", zkelf::p_flags::PF_X)
        .value("read", zkelf::p_flags::PF_R)
        .value("write", zkelf::p_flags::PF_W)
        .export_values()
        .doc() = "permissions of the segment";

    init_phdr_for_x64(zkelf);
    init_phdr_for_x86(zkelf);

    py::enum_<zkelf::sh_n>(zkelf, "sh_n")
        .value("SHN_UNDEF", zkelf::sh_n::SHN_UNDEF)
        .value("SHN_LORESERVE", zkelf::sh_n::SHN_LORESERVE)
        .value("SHN_LOPROC", zkelf::sh_n::SHN_LOPROC)
        .value("SHN_BEFORE", zkelf::sh_n::SHN_BEFORE)
        .value("SHN_AFTER", zkelf::sh_n::SHN_AFTER)
        .value("SHN_HIPROC", zkelf::sh_n::SHN_HIPROC)
        .value("SHN_LOOS", zkelf::sh_n::SHN_LOOS)
        .value("SHN_HIOS", zkelf::sh_n::SHN_HIOS)
        .value("SHN_ABS", zkelf::sh_n::SHN_ABS)
        .value("SHN_COMMON", zkelf::sh_n::SHN_COMMON)
        .value("SHN_XINDEX", zkelf::sh_n::SHN_XINDEX)
        .value("SHN_HIRESERVE", zkelf::sh_n::SHN_HIRESERVE)
        .export_values()
        .doc() = "TODO";  // TODO

    py::enum_<zkelf::s_type>(zkelf, "s_type")
        .value("SHT_NULL", zkelf::s_type::SHT_NULL)
        .value("SHT_PROGBITS", zkelf::s_type::SHT_PROGBITS)
        .value("SHT_SYMTAB", zkelf::s_type::SHT_SYMTAB)
        .value("SHT_STRTAB", zkelf::s_type::SHT_STRTAB)
        .value("SHT_RELA", zkelf::s_type::SHT_RELA)
        .value("SHT_HASH", zkelf::s_type::SHT_HASH)
        .value("SHT_DYNAMIC", zkelf::s_type::SHT_DYNAMIC)
        .value("SHT_NOTE", zkelf::s_type::SHT_NOTE)
        .value("SHT_NOBITS", zkelf::s_type::SHT_NOBITS)
        .value("SHT_REL", zkelf::s_type::SHT_REL)
        .value("SHT_SHLIB", zkelf::s_type::SHT_SHLIB)
        .value("SHT_DYNSYM", zkelf::s_type::SHT_DYNSYM)
        .value("SHT_INIT_ARRAY", zkelf::s_type::SHT_INIT_ARRAY)
        .value("SHT_FINI_ARRAY", zkelf::s_type::SHT_FINI_ARRAY)
        .value("SHT_PREINIT_ARRAY", zkelf::s_type::SHT_PREINIT_ARRAY)
        .value("SHT_GROUP", zkelf::s_type::SHT_GROUP)
        .value("SHT_SYMTAB_SHNDX", zkelf::s_type::SHT_SYMTAB_SHNDX)
        .value("SHT_NUM", zkelf::s_type::SHT_NUM)
        .value("SHT_LOOS", zkelf::s_type::SHT_LOOS)
        .value("SHT_GNU_ATTRIBUTES", zkelf::s_type::SHT_GNU_ATTRIBUTES)
        .value("SHT_GNU_HASH", zkelf::s_type::SHT_GNU_HASH)
        .value("SHT_GNU_LIBLIST", zkelf::s_type::SHT_GNU_LIBLIST)
        .value("SHT_CHECKSUM", zkelf::s_type::SHT_CHECKSUM)
        .value("SHT_LOSUNW", zkelf::s_type::SHT_LOSUNW)
        .value("SHT_SUNW_move", zkelf::s_type::SHT_SUNW_move)
        .value("SHT_SUNW_COMDAT", zkelf::s_type::SHT_SUNW_COMDAT)
        .value("SHT_SUNW_syminfo", zkelf::s_type::SHT_SUNW_syminfo)
        .value("SHT_GNU_verdef", zkelf::s_type::SHT_GNU_verdef)
        .value("SHT_GNU_verneed", zkelf::s_type::SHT_GNU_verneed)
        .value("SHT_GNU_versym", zkelf::s_type::SHT_GNU_versym)
        .value("SHT_HISUNW", zkelf::s_type::SHT_HISUNW)
        .value("SHT_HIOS", zkelf::s_type::SHT_HIOS)
        .value("SHT_LOPROC", zkelf::s_type::SHT_LOPROC)
        .value("SHT_HIPROC", zkelf::s_type::SHT_HIPROC)
        .value("SHT_LOUSER", zkelf::s_type::SHT_LOUSER)
        .value("SHT_HIUSER", zkelf::s_type::SHT_HIUSER)
        .export_values()
        .doc() = "TODO";  // TODO

    py::enum_<zkelf::sh_flags>(zkelf, "sh_flags")
        .value("SHF_WRITE", zkelf::sh_flags::SHF_WRITE)
        .value("SHF_ALLOC", zkelf::sh_flags::SHF_ALLOC)
        .value("SHF_EXECINSTR", zkelf::sh_flags::SHF_EXECINSTR)
        .value("SHF_MERGE", zkelf::sh_flags::SHF_MERGE)
        .value("SHF_STRINGS", zkelf::sh_flags::SHF_STRINGS)
        .value("SHF_INFO_LINK", zkelf::sh_flags::SHF_INFO_LINK)
        .value("SHF_LINK_ORDER", zkelf::sh_flags::SHF_LINK_ORDER)
        .value("SHF_OS_NONCONFORMING",
               zkelf::sh_flags::SHF_OS_NONCONFORMING)
        .value("SHF_GROUP", zkelf::sh_flags::SHF_GROUP)
        .value("SHF_TLS", zkelf::sh_flags::SHF_TLS)
        .value("SHF_COMPRESSED", zkelf::sh_flags::SHF_COMPRESSED)
        .export_values()
        .doc() = "section flags";

    init_shdr_for_x64(zkelf);
    init_shdr_for_x86(zkelf);

    py::enum_<zkelf::st_info>(zkelf, "st_info")
        .value("STT_NOTYPE", zkelf::st_info::STT_NOTYPE)
        .value("STT_OBJECT", zkelf::st_info::STT_OBJECT)
        .value("STT_FUNC", zkelf::st_info::STT_FUNC)
        .value("STT_SECTION", zkelf::st_info::STT_SECTION)
        .value("STT_FILE", zkelf::st_info::STT_FILE)
        .value("STT_COMMON", zkelf::st_info::STT_COMMON)
        .value("STT_TLS", zkelf::st_info::STT_TLS)
        .value("STT_LOOS", zkelf::st_info::STT_LOOS)
        .value("STT_GNU_IFUNC", zkelf::st_info::STT_GNU_IFUNC)
        .value("STT_HIOS", zkelf::st_info::STT_HIOS)
        .value("STT_HIPROC", zkelf::st_info::STT_HIPROC)
        .export_values()
        .doc() = "symbol info";

    py::enum_<zkelf::st_other>(zkelf, "st_other")
        .value("STV_DEFAULT", zkelf::st_other::STV_DEFAULT)
        .value("STV_INTERNAL", zkelf::st_other::STV_INTERNAL)
        .value("STV_HIDDEN", zkelf::st_other::STV_HIDDEN)
        .value("STV_PROTECTED", zkelf::st_other::STV_PROTECTED)
        .export_values()
        .doc() = "symbol visibilty";

    init_symtab_for_x64(zkelf);
    init_symtab_for_x86(zkelf);

    py::enum_<zkelf::d_tag>(zkelf, "d_tag")
        .value("DT_NULL", zkelf::d_tag::DT_NULL)
        .value("DT_NEEDED", zkelf::d_tag::DT_NEEDED)
        .value("DT_PLTRELSZ", zkelf::d_tag::DT_PLTRELSZ)
        .value("DT_PLTGOT", zkelf::d_tag::DT_PLTGOT)
        .value("DT_HASH", zkelf::d_tag::DT_HASH)
        .value("DT_STRTAB", zkelf::d_tag::DT_STRTAB)
        .value("DT_SYMTAB", zkelf::d_tag::DT_SYMTAB)
        .value("DT_RELA", zkelf::d_tag::DT_RELA)
        .value("DT_RELASZ", zkelf::d_tag::DT_RELASZ)
        .value("DT_RELAENT", zkelf::d_tag::DT_RELAENT)
        .value("DT_STRSZ", zkelf::d_tag::DT_STRSZ)
        .value("DT_SYMENT", zkelf::d_tag::DT_SYMENT)
        .value("DT_INIT", zkelf::d_tag::DT_INIT)
        .value("DT_FINI", zkelf::d_tag::DT_FINI)
        .value("DT_SONAME", zkelf::d_tag::DT_SONAME)
        .value("DT_RPATH", zkelf::d_tag::DT_RPATH)
        .value("DT_SYMBOLIC", zkelf::d_tag::DT_SYMBOLIC)
        .value("DT_REL", zkelf::d_tag::DT_REL)
        .value("DT_RELSZ", zkelf::d_tag::DT_RELSZ)
        .value("DT_RELENT", zkelf::d_tag::DT_RELENT)
        .value("DT_PLTREL", zkelf::d_tag::DT_PLTREL)
        .value("DT_DEBUG", zkelf::d_tag::DT_DEBUG)
        .value("DT_TEXTREL", zkelf::d_tag::DT_TEXTREL)
        .value("DT_JMPREL", zkelf::d_tag::DT_JMPREL)
        .value("DT_BIND_NOW", zkelf::d_tag::DT_BIND_NOW)
        .value("DT_INIT_ARRAY", zkelf::d_tag::DT_INIT_ARRAY)
        .value("DT_FINI_ARRAY", zkelf::d_tag::DT_FINI_ARRAY)
        .value("DT_INIT_ARRAYSZ", zkelf::d_tag::DT_INIT_ARRAYSZ)
        .value("DT_FINI_ARRAYSZ", zkelf::d_tag::DT_FINI_ARRAYSZ)
        .value("DT_RUNPATH", zkelf::d_tag::DT_RUNPATH)
        .value("DT_FLAGS", zkelf::d_tag::DT_FLAGS)
        .value("DT_ENCODING", zkelf::d_tag::DT_ENCODING)
        .value("DT_PREINIT_ARRAY", zkelf::d_tag::DT_PREINIT_ARRAY)
        .value("DT_PREINIT_ARRAYSZ", zkelf::d_tag::DT_PREINIT_ARRAYSZ)
        .value("DT_NUM", zkelf::d_tag::DT_NUM)
        .value("DT_LOOS", zkelf::d_tag::DT_LOOS)
        .value("DT_HIOS", zkelf::d_tag::DT_HIOS)
        .value("DT_LOPROC", zkelf::d_tag::DT_LOPROC)
        .value("DT_HIPROC", zkelf::d_tag::DT_HIPROC)
        .export_values()
        .doc() = "tags of dynamic section entries";

    init_relocation_for_x64(zkelf);
    init_relocation_for_x86(zkelf);

    init_dynamic_for_x64(zkelf);
    init_symtab_for_x86(zkelf);

    init_nhdr_for_x64(zkelf);
    init_nhdr_for_x86(zkelf);

    init_elfobj_for_x64(zkelf);
    init_elfobj_for_x86(zkelf);

    py::class_<zkelf::elf_read_only>(zkelf, "elf_read_only")
        .def(py::init())
        .doc() = "elf binaries that are opened only for read";

    py::enum_<zkelf::elf_save_options>(zkelf, "elf_save_options")
        .value("ELF_AUTO_SAVE", zkelf::elf_save_options::ELF_AUTO_SAVE)
        .value("ELF_SAVE_AT_EXIT",
               zkelf::elf_save_options::ELF_SAVE_AT_EXIT)
        .value("ELF_NO_SAVE", zkelf::elf_save_options::ELF_NO_SAVE)
        .export_values()
        .doc() = "save options for elf binaries opened for read and write";

    py::class_<zkelf::elf_read_write>(zkelf, "elf_read_write")
        .def_readwrite("save_options",
                       &zkelf::elf_read_write::save_options)
        .doc() = "elf binaries that are opened for both read and write";
}
