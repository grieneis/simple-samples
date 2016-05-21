cmake_minimum_required (VERSION 2.6)
project (test)

include_directories( "${PROJECT_SRC_DIR}/src" )

add_executable(simpleApp src/main.cpp
                    src/sorts.cpp
                    src/utils.cpp
                    src/datastructs.cpp)
