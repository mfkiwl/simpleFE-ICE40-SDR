add_executable(test_blkconv test_blkconv.cxx)
target_link_libraries(test_blkconv LINK_PUBLIC Libdsp)

find_package(SWIG REQUIRED)
find_package(Python2 COMPONENTS Interpreter Development)
find_package(NumPy REQUIRED)

INCLUDE(${SWIG_USE_FILE})

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)

set_property(SOURCE pydsp.i PROPERTY CPLUSPLUS ON)
SWIG_ADD_LIBRARY(pydsp LANGUAGE python SOURCES pydsp.i)
set_property(TARGET pydsp PROPERTY SWIG_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/..)
set_property(TARGET pydsp PROPERTY SWIG_GENERATED_INCLUDE_DIRECTORIES ${Python2_INCLUDE_DIRS} ${PYTHON_NUMPY_INCLUDE_DIR})

SWIG_LINK_LIBRARIES(pydsp Libdsp)
