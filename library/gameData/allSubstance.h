/***************************************************************
* 特别的，泛指所有的可被进行动作的物体，包括生命体
****************************************************************/
#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "substance.h"

class GAMEDATA_EXPORT allSubstance : public substance
{
public:
	allSubstance();
	~allSubstance();

protected:
};

