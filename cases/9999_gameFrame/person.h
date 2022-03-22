#pragma once
#include <string>

#include "baseObject.h"

class person : public baseObject
{
public:
	person();
	~person();

	void SetName(const std::string& name);
	std::string GetName();

	virtual std::string GetWord() = 0;

protected:
	std::string m_id;
	std::string m_name;
};
