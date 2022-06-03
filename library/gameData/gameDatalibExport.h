#ifndef __gameDataExport_h__
#define __gameDataExport_h__

#if defined _WIN32
#  if defined(GAMEDATA_EXPORTS)
#    define GAMEDATA_EXPORT __declspec(dllexport)
#  else
#    define GAMEDATA_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMEDATA_EXPORT)
#    define GAMEDATA_EXPORT __declspec(dllexport)
#endif
#else
  #if __GUNC__ >= 4
    #  if defined(GAMEDATA_EXPORTS)
      #define GAMEDATA_EXPORT __attribute__ ((visibility ("default")))
    #else
      #define GAMEDATA_EXPORT __attribute__ ((visibility ("hidden")))
    #endif
  #else
    #define GAMEDATA_EXPORT
  #endif
#endif

#endif

