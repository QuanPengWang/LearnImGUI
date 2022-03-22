project(9999_gameFrame)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/include
)

LINK_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/lib-vc2010-64/
)

set(header_files
  mainWindow.h
  gameWindow.h
)

set(source_files
  mainWindow.cpp
  gameWindow.cpp
  main.cpp
)

add_executable(${PROJECT_NAME}
  ${header_files}
  ${source_files}
)

target_link_libraries(${PROJECT_NAME}
  opengl32
  glfw3
  imgui
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(WithConsole)
    set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE false)
  else()
    set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)
    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY LINK_FLAGS "/entry:mainCRTStartup")
  endif()
endif()