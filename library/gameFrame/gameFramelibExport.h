#ifndef __gameFrameExport_h__
#define __gameFrameExport_h__

#  if defined(GAMEFRAME_EXPORTS)
#    define GAMEFRAME_EXPORT __declspec(dllexport)
#  else
#    define GAMEFRAME_EXPORT __declspec(dllimport)
#  endif

#if !defined(GAMEFRAME_EXPORT)
#    define GAMEFRAME_EXPORT __declspec(dllexport)
#endif

#endif

