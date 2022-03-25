#ifndef __gameWindowExport_h__
#define __gameWindowExport_h__

#  if defined(GAMEWINDOW_EXPORTS)
#    define GAMEWINDOW_EXPORT __declspec(dllexport)
#  else
#    define GAMEWINDOW_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMEWINDOW_EXPORT)
#    define GAMEWINDOW_EXPORT __declspec(dllexport)
#endif

#endif

