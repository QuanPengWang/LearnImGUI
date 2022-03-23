#include "person.h"

person::person()
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

void person::SetEmotion(const person_emotion& emotion)
{
	m_emotion = emotion;
}

person_emotion person::GetEmotion()
{
	return m_emotion;
}
