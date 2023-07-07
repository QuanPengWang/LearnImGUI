/****************************************************************************
* emotion 情绪
* 当其 value < 0 时，代表情绪不好
* 当其 value == 0 时，代表情绪平稳
* 当其 value > 0 时，代表情绪好
* m_description，用来作为描述情绪的字段
****************************************************************************/

#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "baseObject.h"

class GAMEDATA_EXPORT emotion : public baseObject
{
public:
	emotion();
	~emotion();

	void SetValue(const double& v);
	double GetValue();

	void SetDescription(const std::string& des);
	std::string GetDescription();

protected:
	void CheckEmotion();

protected:
	double m_value;
	std::string m_description;
};