cmake_minimum_required(VERSION 3.15)
project(Basic)

set(CMAKE_CXX_STANDARD 14)

# 官方提供了一种递归的方法
file (GLOB_RECURSE files *.cpp)
# file (GLOB files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()