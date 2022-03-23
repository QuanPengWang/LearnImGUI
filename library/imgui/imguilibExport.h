#ifndef __imguiExport_h__
#define __imguiExport_h__

#  if defined(IMGUI_EXPORTS)
#    define IMGUI_EXPORT __declspec(dllexport)
#  else
#    define IMGUI_EXPORT __declspec(dllimport)
#  endif

#if !defined(IMGUI_EXPORT)
#    define IMGUI_EXPORT __declspec(dllexport)
#endif

#endif

