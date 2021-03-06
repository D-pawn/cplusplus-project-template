cmake_minimum_required(VERSION 2.6)

# 编译选项

# 允许c++11标准、O3优化、多线程。match选项可避免一些cpu上的问题  -std=c++11 -march=native -O3
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -pthread" )
ADD_DEFINITIONS( -g -W -Wall -D_REENTRANT -D_FILE_OFFSET_BITS=64 -DAC_HAS_INFO
-DAC_HAS_WARNING -DAC_HAS_ERROR -DAC_HAS_CRITICAL -DTIXML_USE_STL
-DAC_HAS_DEBUG -DLINUX_DAEMON -std=c++0x)

# 基本信息-根

set(ROOT "${CMAKE_CURRENT_LIST_DIR}")

# 基本信息-版本

set(GROUP_ID "")
set(ARTIFACT_ID "")
set(VERSION "1.0.0")

# 基本信息-cpp

set(SRC_ROOT_NAME "src") 
set(SRC_ROOT "${ROOT}/${SRC_ROOT_NAME}")

# 基本信息-目标文件

set(BIN_NAME "test") 
set(BIN_ROOT_NAME "bin") 
set(BIN_ROOT "${ROOT}/${BIN_ROOT_NAME}") 
# 可执行程序的输出目录 -cmake变量
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_ROOT})
# 动态库的输出目录-cmake变量
set(LIBRARY_OUTPUT_PATH ${BIN_ROOT}) 

# 基本信息-依赖库

# LIBER库
set(LIBER_ROOT "/var/lib/liber")
set(LIBER_BASE_ROOT "${ROOT}/../../base")

# 项目库
set(LIB_ROOT_NAME "lib")
set(LIB_ROOT "${ROOT}/${LIB_ROOT_NAME}")

# 基本信息-头文件

set(INCLUDE_ROOT_NAME "include") 
set(INCLUDE_ROOT "${ROOT}/${INCLUDE_ROOT_NAME}")
set(INCLUDE_SRC_ROOT "${INCLUDE_ROOT}/${GROUP_ID}/${ARTIFACT_ID}")

# 关联-cpp

# 基础模块
aux_source_directory("${SRC_ROOT}" SRC_LIST)
aux_source_directory("${SRC_ROOT}/ld" SRC_LIST)
aux_source_directory("${SRC_ROOT}/global" SRC_LIST)
aux_source_directory("${INCLUDE_SRC_ROOT}/template" SRC_LIST)

# 关联-库文件

#set(INCLUDE_LIB_LIST ${INCLUDE_LIB_LIST} "${LIBER_BASE_ROOT}/pb-protocol/include/attachdata") 

# 构建-头文件

set(INCLUDE_LIST ${INCLUDE_LIST} "${INCLUDE_ROOT}")
set(INCLUDE_SRC_LIST ${INCLUDE_SRC_LIST} "${INCLUDE_SRC_ROOT}" "${SRC_ROOT}")
set(INCLUDE_LIB_LIST ${INCLUDE_LIB_LIST} "${INCLUDE_LIB_DYNAMIC_LIST}" "${LIB_ROOT}" "${LIBER_BASE_ROOT}" "${LIBER_ROOT}")
set(INCLUDE_SYSTEM_LIST ${INCLUDE_SYSTEM_LIST} "/usr/include")
set(INCLUDE_LIST  ${INCLUDE_LIST} ${INCLUDE_SRC_LIST} ${INCLUDE_LIB_LIST} ${INCLUDE_SYSTEM_LIST})

# 构建-编译连接

include_directories(${INCLUDE_LIST})
link_directories(${LIB_LIST})
add_executable(${BIN_NAME} ${SRC_LIST})
target_link_libraries(${BIN_NAME} ${LIB_NAME_LIST})

# 日志
message("===log CMAKE_CXX_FLAGS===:" ${COMPILE_DEFINITIONS})
message("===log SRC_LIST===:" ${SRC_LIST})
message("===log INCLUDE_LIST===:" ${INCLUDE_LIST})
message("===log LIB_LIST===:" ${LIB_LIST})
message("===log LIB_NAME_LIST===:" ${LIB_NAME_LIST})
message("===log CMAKE_CURRENT_BINARY_DIR===:" ${CMAKE_CURRENT_BINARY_DIR})
