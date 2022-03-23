#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include <string>
#include "baseObject.h"
#include "personDefine.h"

class emotion;
class GAMEFRAME_EXPORT person : public baseObject
{
public:
	person();
	~person();

	void SetName(const std::string& name);
	std::string GetName();

	void SetEmotion(emotion* emotion);
	emotion* GetEmotion();

	virtual std::string GetWord() = 0;

protected:
	std::string m_id;
	std::string m_name;
	emotion* m_emotion;
};
