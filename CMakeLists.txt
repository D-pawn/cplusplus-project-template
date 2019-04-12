cmake_minimum_required(VERSION 2.8)

#基本自定义变量-自定义变量
set(ROOT "${CMAKE_CURRENT_LIST_DIR}")
set(SRC_ROOT_NAME "src") 
set(BIN_ROOT_NAME "bin") 
set(BIN_NAME "testcpp") 
set(BIN_INCLUDE_ROOT_NAME "include") 
set(BIN_LIB_ROOT_NAME "lib") 
set(BIN_LIB_SO_ROOT_NAME "dynamic") 
set(BIN_LIB_A_ROOT_NAME "static") 
set(BIN_LIB_TEMP_ROOT_NAME "temp") 

#当前项目定义-自定义变量
set(SRC_ROOT "${ROOT}/${SRC_ROOT_NAME}")
set(SRC_LIST "")
set(BIN_ROOT "${ROOT}/${BIN_ROOT_NAME}") 
set(INCLUDE_ROOT "${SRC_ROOT}" "${ROOT}/${BIN_INCLUDE_ROOT_NAME}")  #C++编译时，教科书中写道:#include “headfile.h”优先在当前目录查找头文件 
set(LIB_ROOT "${SRC_ROOT}"  "${ROOT}/${BIN_LIB_ROOT_NAME}") 
set(LIB_SO_ROOT "${SRC_ROOT}" "${LIB_ROOT}/${BIN_LIB_SO_ROOT_NAME}")
set(LIB_A_ROOT  "${SRC_ROOT}" "${LIB_ROOT}/${BIN_LIB_A_ROOT_NAME}")
set(LIB_TEMP_ROOT "${SRC_ROOT}/${BIN_LIB_TEMP_NAME}")
set(LIB_LIST "libtesth.so") 

#通过cmake命令设置变量
aux_source_directory(${SRC_ROOT} SRC_LIST)

#cmake变量-cmake变量
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_ROOT})

#项目编译连接
include_directories(${INCLUDE_ROOT})
link_directories(${LIB_ROOT})
add_executable(${BIN_NAME} ${SRC_LIST})
target_link_libraries(${BIN_NAME} ${LIB_LIST})
#message("===log===:" ${CMAKE_CURRENT_BINARY_DIR})
