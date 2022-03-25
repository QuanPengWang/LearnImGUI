#include "person.h"
#include "emotion.h"
#include "properties.h"

person::person()
	:m_emotion(new emotion)
{
}

person::~person()
{
}

void person::SetEmotion(emotion* emotion)
{
	m_emotion = emotion;
}

emotion* person::GetEmotion()
{
	return m_emotion;
}

void person::SetProperties(properties* pro)
{
	if(std::find(m_bag.begin(), m_bag.end(), pro) == m_bag.end())
	{
		m_bag.push_back(pro);
	}
}

std::vector<properties*> person::GetProperties()
{
	return m_bag;
}
