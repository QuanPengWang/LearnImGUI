#ifndef __gameLoaderExport_h__
#define __gameLoaderExport_h__

#if defined _WIN32
#  if defined(GAMELOADER_EXPORTS)
#    define GAMELOADER_EXPORT __declspec(dllexport)
#  else
#    define GAMELOADER_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMELOADER_EXPORT)
#    define GAMELOADER_EXPORT __declspec(dllexport)
#endif
#else
  #if __GUNC__ >= 4
    #  if defined(GAMELOADER_EXPORTS)
      #define GAMELOADER_EXPORT __attribute__ ((visibility ("default")))
    #else
      #define GAMELOADER_EXPORT __attribute__ ((visibility ("hidden")))
    #endif
  #else
    #define GAMELOADER_EXPORT
  #endif
#endif

#endif

