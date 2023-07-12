project(gameData)

string(TOUPPER ${PROJECT_NAME} LibraryName)
add_definitions("-D ${LibraryName}_EXPORTS")

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${OPENGL_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/backends
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/include
)

LINK_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/thirdParty/imgui/examples/libs/glfw/lib-vc2010-64/
)

set(header_files
  uuid.h
  baseObject.h
  organism.h
  organ.h
  person.h
  person_npc.h
  person_player.h
  emotion.h
  action.h
  action_greetings.h
  properties.h
)

set(source_files
  baseObject.cpp
  organism.cpp
  organ.cpp
  person.cpp
  person_npc.cpp
  person_player.cpp
  emotion.cpp
  action.cpp
  action_greetings.cpp
  properties.cpp
)

add_library(${PROJECT_NAME} SHARED
  ${header_files}
  ${source_files}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  ${OPENGL_LIBRARY}
  glfw
  imgui
)