project(gameDemo)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/library/gameData
  ${CMAKE_SOURCE_DIR}/library/gameWindow
  ${CMAKE_SOURCE_DIR}/library/gameFrame
  ${CMAKE_SOURCE_DIR}/library/gameLoader
)

LINK_DIRECTORIES(

)

set(header_files
)

set(source_files
  main.cpp
)

add_executable(${PROJECT_NAME}
  ${header_files}
  ${source_files}
)

target_link_libraries(${PROJECT_NAME}
  gameData
  gameWindow
  gameFrame
  gameLoader
)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  if(WithConsole)
    set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE false)
  else()
    set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)
    set_property(TARGET ${PROJECT_NAME} APPEND PROPERTY LINK_FLAGS "/entry:mainCRTStartup")
  endif()
endif()