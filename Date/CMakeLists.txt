#CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(date)

#编译配置选择"Debug"才能调试
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")

#将hello.cpp生成test01可执行文件
add_executable(main main.cpp)

