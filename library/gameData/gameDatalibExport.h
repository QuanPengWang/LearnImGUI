#ifndef __gameDataExport_h__
#define __gameDataExport_h__

#  if defined(GAMEDATA_EXPORTS)
#    define GAMEDATA_EXPORT __declspec(dllexport)
#  else
#    define GAMEDATA_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMEDATA_EXPORT)
#    define GAMEDATA_EXPORT __declspec(dllexport)
#endif

#endif

