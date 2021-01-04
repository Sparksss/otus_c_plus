cmake_minimum_required(VERSION 3.18)

# set project name
if($ENV{TRAVIS_BUILD_NUMBER})
    project(otus_cpp VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(otus_cpp VERSION 0.0.42)
endif()

# find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

# add executable
add_executable(otus_cpp main.cpp)
add_library(otus_cpp_lib lib.cpp)

# specify the c++ standart
set_target_properties(
    otus_cpp 
    otus_cpp_lib PROPERTIES 
    CXX_STANDARD 14 
    CXX_STANDARD_REQUIRED ON 
)

target_include_directories(otus_cpp PRIVATE "${PROJECT_BINARY_DIR}")

install(TARGETS otus_cpp RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
