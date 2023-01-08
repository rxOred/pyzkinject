cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(pyzkinject)

set(PYTHON_LIBRARY_DIR "/home/rxored/.local/lib/python3.10/site-packages")
set(PYTHON_EXECUTABLE "/usr/bin/python3.10")
set(ZKINJECT_SOURCE_FILES "~/repos/zkinject/src/*.cc")
set(ZKINJECT_INCLUDE_PATH "~/repos/zkinject/include/*.hh")

include_directories("~/repos/zkinject/include/")
include_directories("${CMAKE_SOURCE_DIR}/python")

# just for this case
file(GLOB SOURCE_FILES ${ZKINJECT_SOURCE_FILES})
file(GLOB HEADER_FILES ${ZKINJECT_INCLUDE_FILES})
file(GLOB PYTHON_FILES "python/*.cpp" "python/*.hpp")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES} ${HEADER_FILES} ${PYTHON_FILES})

find_package(pybind11 REQUIRED)
pybind11_add_module(pyzkinject
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${PYTHON_FILES}
        )

target_link_libraries(pyzkinject PUBLIC)

install(TARGETS pyzkinject
        COMPONENT python
        LIBRARY DESTINATION "${PYTHON_LIBRARY_DIR}"
        )
