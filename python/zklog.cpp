#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <zkinject/zklog.hh>

namespace py = pybind11;

void init_zklog(py::module& m) {
    auto zklog = m.def_submodule("zklog");
    zklog.doc() = "zkinject's logger";

    py::enum_<zklog::log_level>(zklog, "log_level")
        .value("LOG_LEVEL_DEBUG", zklog::log_level::LOG_LEVEL_DEBUG)
        .value("LOG_LEVEL_ERROR", zklog::log_level::LOG_LEVEL_ERROR)
        .value("LOG_LEVEL_CRITICAL", zklog::log_level::LOG_LEVEL_CRITICAL)
        .export_values();

    py::enum_<zklog::log_error_code>(zklog, "log_error_code")
        .value("LOG_ERROR_NONE", zklog::log_error_code::LOG_ERROR_NONE)
        .value("LOG_ERROR_INVALID_FILE_TYPE",
               zklog::log_error_code::LOG_ERROR_INVALID_FILE_TYPE)
        .value("LOG_ERROR_INVALID_SECTION",
               zklog::log_error_code::LOG_ERROR_INVALID_SECTION)
        .value("LOG_ERROR_INVALID_SEGMENT",
               zklog::log_error_code::LOG_ERROR_INVALID_SEGMENT)
        .value("LOG_ERROR_INVALID_SYMBOL",
               zklog::log_error_code::LOG_ERROR_INALID_SYMBOL)
        .value("LOG_ERROR_INDDEX_OUT_OF_RANGE",
               zklog::log_error_code::LOG_ERROR_INDEX_OUT_OF_RANGE)
        .export_values();

    using namespace pybind11::literals;  // for arguments
    py::class_<zklog::ZkLog>(zklog, "Zklog")
        // zklog is meant to be used as a singleton.
        .def_static("get_logger", zklog::ZkLog::get_logger,
                    py::return_value_policy::reference)
        .def("set_log_buffer_count", &zklog::ZkLog::set_log_buffer_count)
        .def("clear_log", &zklog::ZkLog::clear_log)
        // push_log accepts an optoinal argument for log_error_code.
        // by default, it is set to LOG_ERROR_NONE
        .def("push_log", &zklog::ZkLog::push_log, "log_string"_a,
             "level"_a,
             py::arg_v("error_code", zklog::log_error_code::LOG_ERROR_NONE,
                       "None"))
        .def("pop_log", &zklog::ZkLog::pop_log)
        .def("peek_log_level", &zklog::ZkLog::peek_log_level);
}