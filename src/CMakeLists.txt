cmake_minimum_required(VERSION 3.18)

# set project name
project(otus_c++ VERSION 1.0)

# specify the c++ standart
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add executable
add_executable(otus_c++ main.cpp)

# configure_file(TutorialConfig.h.in TutorialConfig.h)
# target_include_directories(otus_c++ PUBLIC "${PROJECT_BINARY_DIR}")
