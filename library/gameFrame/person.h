#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include <string>
#include <map>
#include "baseObject.h"

class emotion;
class action;
class properties;
class GAMEFRAME_EXPORT person : public baseObject
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
