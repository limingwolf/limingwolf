# CMakeList.txt: UseImageWidget 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
  set (CMAKE_CXX_STANDARD 17)
  set (CMAKE_CXX_STANDARD_REQUIRED ON)

  set(CMAKE_AUTOMOC ON)
  set(CMAKE_AUTOUIC ON)
  set(CMAKE_INCLUDE_CURRENT_DIR ON)


  set(CMAKE_PREFIX_PATH "E:\Program\Qt5.15\5.15.2\msvc2019_64")
  find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

  add_executable (UseImageWidget main.cpp)

 # target_link_libraries(UseImageWidget Qt5::Widgets)


 

 

 
