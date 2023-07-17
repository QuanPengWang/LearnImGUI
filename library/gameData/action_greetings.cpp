#include "action_greetings.h"

#include "emotion.h"
#include "person.h"

action_greetings::action_greetings()
{
	SetName(u8"打招呼");
}

action_greetings::~action_greetings()
{

}

bool action_greetings::DoAction()
{
	if(m_subject || m_object)
	{
		m_count++;
		person* p = static_cast<person*>(m_object);
		if(p)
		{
			double increment = 0.0;
			if (m_count < 3)
				increment = 0.1;
			else if (3 <= m_count && m_count < 10)
				increment = -0.1;
			else if (10 <= m_count)
				increment = -(m_count * 10);

			emotion* em = p->GetEmotion();
			if(em)
			{
				double newEmValue = em->GetValue() + increment;
				em->SetValue(newEmValue);
			}
		}

		return true;
	}

	return false;
}
