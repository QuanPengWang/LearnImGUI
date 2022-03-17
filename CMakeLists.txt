cmake_minimum_required(VERSION 3.0.0)
project(LearnImGUI VERSION 1.0.0)

# 使用 utf-8 编码
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(library)
add_subdirectory(cases)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(EXISTS $ENV{HOMEPATH}/Desktop/${PROJECT_NAME}.bat)
  else()
    set(ProjectFile ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.sln)
    configure_file(desktopBat.in $ENV{HOMEPATH}/Desktop/${PROJECT_NAME}.bat)
  endif()
endif()