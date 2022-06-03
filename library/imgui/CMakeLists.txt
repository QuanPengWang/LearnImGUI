project(imgui)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/include
)

LINK_DIRECTORIES(
  #${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/lib-vc2010-64/
)

set(header_files
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends/imgui_impl_glfw.h
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends/imgui_impl_opengl3.h
)

set(source_files
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/imgui.cpp
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/imgui_demo.cpp
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/imgui_draw.cpp
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/imgui_tables.cpp
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/imgui_widgets.cpp
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends/imgui_impl_glfw.cpp
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends/imgui_impl_opengl3.cpp
)

add_library(${PROJECT_NAME}
  ${header_files}
  ${source_files}
)

target_link_libraries(${PROJECT_NAME}
  #opengl32
  ${OPENGL_LIBRARY}
  glfw
  #glfw-3.3.4_1
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_link_libraries(${PROJECT_NAME}
    legacy_stdio_definitions
  )
endif()