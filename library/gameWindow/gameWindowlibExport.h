#ifndef __gameWindowExport_h__
#define __gameWindowExport_h__

#if defined _WIN32
#  if defined(GAMEWINDOW_EXPORTS)
#    define GAMEWINDOW_EXPORT __declspec(dllexport)
#  else
#    define GAMEWINDOW_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMEWINDOW_EXPORT)
#    define GAMEWINDOW_EXPORT __declspec(dllexport)
#endif
#else
  #if __GUNC__ >= 4
    #  if defined(GAMEWINDOW_EXPORTS)
      #define GAMEWINDOW_EXPORT __attribute__ ((visibility ("default")))
    #else
      #define GAMEWINDOW_EXPORT __attribute__ ((visibility ("hidden")))
    #endif
  #else
    #define GAMEWINDOW_EXPORT
  #endif
#endif

#endif

