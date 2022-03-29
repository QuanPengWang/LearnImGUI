#ifndef __gameLoaderExport_h__
#define __gameLoaderExport_h__

#  if defined(GAMELOADER_EXPORTS)
#    define GAMELOADER_EXPORT __declspec(dllexport)
#  else
#    define GAMELOADER_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMELOADER_EXPORT)
#    define GAMELOADER_EXPORT __declspec(dllexport)
#endif

#endif

