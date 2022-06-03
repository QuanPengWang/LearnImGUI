#ifndef __imguiExport_h__
#define __imguiExport_h__

#if defined _WIN32
#  if defined(IMGUI_EXPORTS)
#    define IMGUI_EXPORT __declspec(dllexport)
#  else
#    define IMGUI_EXPORT __declspec(dllimport)
#  endif

#if !defined(IMGUI_EXPORT)
#    define IMGUI_EXPORT __declspec(dllexport)
#endif
#else
  #if __GUNC__ >= 4
    #  if defined(IMGUI_EXPORTS)
      #define IMGUI_EXPORT __attribute__ ((visibility ("default")))
    #else
      #define IMGUI_EXPORT __attribute__ ((visibility ("hidden")))
    #endif
  #else
    #define IMGUI_EXPORT
  #endif
#endif

#endif

