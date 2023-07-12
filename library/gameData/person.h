/******************************************************************************
* 成员：
*	情绪
*	随身物品
*	动作
******************************************************************************/

#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include <string>
#include <map>
#include "organism.h"

class emotion;
class action;
class properties;
class GAMEDATA_EXPORT person : public organism
{
public:
	person();
	~person();

	void SetEmotion(emotion* emotion);
	emotion* GetEmotion();

	virtual std::string GetWord() = 0;

	void SetProperties(properties* pro);
	std::vector<properties*> GetProperties();

protected:
	emotion* m_emotion;
	std::vector<properties*> m_bag;
	std::map<baseObject*, action*> m_actions;
};
