project(gameWindow)

string(TOUPPER ${PROJECT_NAME} LibraryName)
add_definitions("-D ${LibraryName}_EXPORTS")

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/include
  ${CMAKE_SOURCE_DIR}/library/gameData
  ${CMAKE_SOURCE_DIR}/library/gameFrame
)

LINK_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/lib-vc2010-64/
)

set(header_files
  gameWindow.h
  baseWindow.h
  dialogueWindow.h
  controlWindow.h
)

set(source_files
  gameWindow.cpp
  baseWindow.cpp
  dialogueWindow.cpp
  controlWindow.cpp
)

add_library(${PROJECT_NAME} SHARED
  ${header_files}
  ${source_files}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  opengl32
  glfw3
  imgui
  gameData
  gameFrame
)