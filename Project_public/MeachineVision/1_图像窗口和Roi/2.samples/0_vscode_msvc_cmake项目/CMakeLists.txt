cmake_minimum_required(VERSION 3.10)

# 项目名称
project(Project)

# 设置 C++ 标准 stdc++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含目录
include_directories(include)

# 添加源文件
#file(GLOB SOURCES "src/*.cpp")
# 手动列出所有源文件
set(SOURCES
    src/main.cpp
    src/MyLibrary.cpp
)

# 添加可执行文件
add_executable(Project ${SOURCES})
