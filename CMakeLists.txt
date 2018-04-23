cmake_minimum_required (VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
# CMakeLists files in this project can
# refer to the root source directory of the project as ${RESEARCH_SOURCE_DIR} and
# to the root binary directory of the project as ${RESEARCH_BINARY_DIR}. 
project (popdin CXX)
# Recurse into the "phys" and "app" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (project)