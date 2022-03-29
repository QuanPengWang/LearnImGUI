cmake_minimum_required(VERSION 3.0.0)
project(LearnImGUI VERSION 1.0.0)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  # 使用 utf-8 编码
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_MODULE_PATH
  ${CMAKE_SOURCE_DIR}/cmake
  ${CMAKE_MODULE_PATH}
)

option(WithConsole "Show Console" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Output)

# build third party
add_subdirectory(thirdParty)

# build project
add_subdirectory(library)
add_subdirectory(cases)
add_subdirectory(application)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(EXISTS $ENV{HOMEPATH}/Desktop/${PROJECT_NAME}.bat)
  else()
    set(ProjectFile ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.sln)
    configure_file(desktopBat.in $ENV{HOMEPATH}/Desktop/${PROJECT_NAME}.bat)
  endif()
endif()