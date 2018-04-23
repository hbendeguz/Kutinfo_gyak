cmake_minimum_required (VERSION 3.1)
# CMakeLists files in this project can
# refer to the root source directory of the project as ${RESEARCH_SOURCE_DIR} and
# to the root binary directory of the project as ${RESEARCH_BINARY_DIR}. 
project (popdin)
add_executable(app popdin.cpp)

set_target_properties(app PROPERTIES
                      CXX_STANDARD 11
                      CXX_STANDARD_REQUIRED ON)