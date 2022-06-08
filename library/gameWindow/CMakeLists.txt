project(gameWindow)

string(TOUPPER ${PROJECT_NAME} LibraryName)
add_definitions("-D ${LibraryName}_EXPORTS")

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/include
  ${CMAKE_SOURCE_DIR}/library/gameData
  ${CMAKE_SOURCE_DIR}/library/gameFrame
  ${CMAKE_SOURCE_DIR}/library/gameLoader
)

LINK_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/lib-vc2010-64/
)

set(header_files
  gameWindow.h
  baseWindow.h
  dialogueWindow.h
  controlWindow.h
  gameInfoWindow.h
  menuWindow.h
)

set(source_files
  gameWindow.cpp
  baseWindow.cpp
  dialogueWindow.cpp
  controlWindow.cpp
  gameInfoWindow.cpp
  menuWindow.cpp
)

add_library(${PROJECT_NAME} SHARED
  ${header_files}
  ${source_files}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${OPENGL_LIBRARY}
  glfw
  imgui
  gameData
  gameFrame
  gameLoader
)