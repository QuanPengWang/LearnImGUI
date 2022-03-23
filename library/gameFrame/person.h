#pragma once
#include "gameFramelibExport.h"
#include <string>
#include "baseObject.h"
#include "personDefine.h"

class GAMEFRAME_EXPORT person : public baseObject
{
public:
	person();
	~person();

	void SetName(const std::string& name);
	std::string GetName();

	void SetEmotion(const person_emotion& emotion);
	person_emotion GetEmotion();

	virtual std::string GetWord() = 0;

protected:
	std::string m_id;
	std::string m_name;
	person_emotion m_emotion;
};
