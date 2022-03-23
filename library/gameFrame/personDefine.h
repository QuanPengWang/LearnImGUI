#pragma once
#include "gameFramelibExport.h"
#include <string>

typedef struct emotion
{
	// 整体上来讲，id < 0 ,不好的心情
	// 0 < id ,好心情
	int id = 0;	// emotion id
	std::string m_name = u8"平常";
	std::string m_description = u8"普普通通的心情";
} emotion;

typedef struct action
{
	
} action;
