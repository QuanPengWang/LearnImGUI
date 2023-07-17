#include "person.h"
#include "emotion.h"
#include "properties.h"
#include <action_greetings.h>

person::person()
	:m_emotion(new emotion)
{
	organ* hair = new organ("hair");
	
	organ* brain = new organ("brain");

	// face 
	organ* forehead = new organ("forehead");

	// ear
	organ* lEar = new organ("lEar");
	organ* rEar = new organ("rEar");
	organ* ear = new organ("ear");
	ear->AddChildOrgan(lEar);
	ear->AddChildOrgan(rEar);

	organ* eyebrow = new organ("eyebrow");

	// eyes
	organ* lEye = new organ("lEye");
	organ* rEye = new organ("rEye");
	organ* eyes = new organ("eyes");
	eyes->AddChildOrgan(lEye);
	eyes->AddChildOrgan(rEye);

	organ* nose = new organ("nose");

	// mouth
	organ* teeth = new organ("teeth");
	organ* tongue = new organ("tongue");
	organ* mouth = new organ("mouth");
	mouth->AddChildOrgan(teeth);
	mouth->AddChildOrgan(tongue);

	organ* chin = new organ("chin");

	organ* face = new organ("face");
	face->AddChildOrgan(forehead);
	face->AddChildOrgan(eyebrow);
	face->AddChildOrgan(eyes);
	face->AddChildOrgan(nose);
	face->AddChildOrgan(mouth);
	face->AddChildOrgan(chin);

	organ* head = new organ("head");
	head->AddChildOrgan(hair);
	head->AddChildOrgan(ear);
	head->AddChildOrgan(face);
	
	// neck
	organ* neck = new organ("neck");

	// shoulder
	organ* shoulder = new organ("shoulder");
	
	// arm
	organ* arm = new organ("arm");

	// finger
	organ* finger = new organ("finger");

	// hand
	organ* hand = new organ("hand");
	hand->AddChildOrgan(finger);

	// chest 胸部
	organ* chest = new organ("chest");

	// abdomen 腹部
	organ* abdomen = new organ("abdomen");

	// genitals 生殖器
	organ* genitals = new organ("genitals");

	// leg
	organ* leg = new organ("leg");

	// toe
	organ* toe = new organ("toe");

	// foot
	organ* foot = new organ("foot");
	foot->AddChildOrgan(toe);

	m_organs[head->GetID()] = head;

	m_organs[neck->GetID()] = neck;
	m_organs[shoulder->GetID()] = shoulder;
	m_organs[arm->GetID()] = arm;
	m_organs[hand->GetID()] = hand;
	m_organs[finger->GetID()] = finger;
	m_organs[chest->GetID()] = chest;
	m_organs[abdomen->GetID()] = abdomen;
	m_organs[genitals->GetID()] = genitals;
	m_organs[leg->GetID()] = leg;
	m_organs[foot->GetID()] = foot;
	m_organs[toe->GetID()] = toe;

	// 主动性动作
	action_greetings* greeting = new action_greetings;
	m_initiatives[greeting->GetID()] = greeting;

	// 被动性动作
	//action_greetings* greeting = new action_greetings;
	//m_actionables[greeting->GetID()] = greeting;
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
