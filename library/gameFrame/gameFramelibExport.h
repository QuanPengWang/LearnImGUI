#ifndef __gameFrameExport_h__
#define __gameFrameExport_h__

#if defined _WIN32
#  if defined(GAMEFRAME_EXPORTS)
#    define GAMEFRAME_EXPORT __declspec(dllexport)
#  else
#    define GAMEFRAME_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMEFRAME_EXPORT)
#    define GAMEFRAME_EXPORT __declspec(dllexport)
#endif
#else
  #if __GUNC__ >= 4
    #  if defined(GAMEFRAME_EXPORTS)
      #define GAMEFRAME_EXPORT __attribute__ ((visibility ("default")))
    #else
      #define GAMEFRAME_EXPORT __attribute__ ((visibility ("hidden")))
    #endif
  #else
    #define GAMEFRAME_EXPORT
  #endif
#endif

#endif

