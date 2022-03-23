#include "action_greetings.h"

#include "emotion.h"
#include "person.h"

action_greetings::action_greetings()
{

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

				if(newEmValue < 0 && -10 < newEmValue)
				{
					em->SetName(u8"不耐烦");
					em->SetName(u8"看起来略微有点烦躁");
				}
				else if(newEmValue <= -10 && -20 < newEmValue)
				{
					em->SetName(u8"烦躁");
					em->SetName(u8"看起来很烦躁");
				}
				else if(newEmValue <= -20)
				{
					em->SetName(u8"生气");
					em->SetName(u8"看起来生气了");
				}

			}
		}

		return true;
	}

	return false;
}
