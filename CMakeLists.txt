cmake_minimum_required(VERSION 3.18)

# set project name
if($ENV{TRAVIS_BUILD_NUMBER})
    project(otus_cpp VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(otus_cpp VERSION 0.0.42)
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.hpp.in version.hpp)

# add executable
add_executable(otus_cpp main.cpp)
add_library(otus_cpp_lib lib.cpp)
add_executable(test_version test_version.cpp)

# specify the c++ standart
set_target_properties(otus_cpp otus_cpp_lib PROPERTIES 
    CXX_STANDARD 14 
    CXX_STANDARD_REQUIRED ON 
)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(otus_cpp PRIVATE "${CMAKE_BINARY_DIR}")

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(otus_cpp PRIVATE otus_cpp_lib)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    otus_cpp_lib
)

if (MSVC)
    target_compile_options(otus_cpp_lib PRIVATE
        /W4
    )
    target_compile_options(otus_cpp PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(otus_cpp_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(otus_cpp PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()


install(TARGETS otus_cpp RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
