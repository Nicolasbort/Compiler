cmake_minimum_required(VERSION 2.8)

project(compiler)

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_FLAGS "-Wno-attributes -m64 -O3" )

set( antlr_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/trdparty/antilr-runtime/build/include/antlr4-runtime")
set( antlr_LIB_DIR "${PROJECT_SOURCE_DIR}/trdparty/antilr-runtime/build/lib" )

message(STATUS "antlr_INCLUDE_DIR: ${antlr_INCLUDE_DIR}")
message(STATUS "antlr_LIB_DIR: ${antlr_LIB_DIR}")

# project include folder &&
# Antlr include folder
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${antlr_INCLUDE_DIR}
)

# Antlr lib folder
link_directories( 
    ${antlr_LIB_DIR}
)



add_executable(
    ${PROJECT_NAME}
    src/compiler.cpp
    src/ExpLexer.cpp
    src/ExpParser.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    antlr4-runtime
)