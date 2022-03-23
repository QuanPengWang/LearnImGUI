FILE(GLOB Project_Libs ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach(lib ${Project_Libs})
  file(RELATIVE_PATH libName ${CMAKE_CURRENT_SOURCE_DIR} ${lib})
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${libName}/CMakeLists.txt)
	if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${lib}/${lib}LibExport.h)
	else()
	  set(libExportStr "${libName}_EXPORT")
	  string(TOUPPER ${libExportStr} LIBRARY_EXPORT_DIRECTIVE)
	  set(LIBRARY_HEADER_PREFIX ${libName})
	  string(TOUPPER ${libName} LIBRARY_LIBNAME)
	  configure_file(
                 LibraryExport.h.in
                 ${CMAKE_CURRENT_SOURCE_DIR}/${libName}/${libName}libExport.h
                 )
	endif()
	add_subdirectory(${libName})
	set_property(TARGET ${libName} PROPERTY FOLDER "libs")
  else()
  endif()
endforeach()
