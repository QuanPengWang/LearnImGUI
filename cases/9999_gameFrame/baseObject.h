#pragma once
#include <vector>
#include <string>

// virtual class
class baseObject
{
public:
	baseObject();
	~baseObject();

	void SetID(const std::string& id);
	std::string GetID();

protected:

private:
	std::string m_id;
};