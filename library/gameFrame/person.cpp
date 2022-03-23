#include "person.h"
#include "emotion.h"

person::person()
	:m_emotion(new emotion)
{
}

person::~person()
{
}

void person::SetName(const std::string& name)
{
	m_name = name;
}

std::string person::GetName()
{
	return m_name;
}

void person::SetEmotion(emotion* emotion)
{
	m_emotion = emotion;
}

emotion* person::GetEmotion()
{
	return m_emotion;
}
