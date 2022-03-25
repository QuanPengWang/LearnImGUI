#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include <vector>
#include <string>

// virtual class
class GAMEDATA_EXPORT baseObject
{
public:
	baseObject();
	~baseObject();

	void SetID(const std::string& id);
	std::string GetID();

	void SetName(const std::string& name);
	std::string GetName();

protected:
	std::string m_id;
	std::string m_name;
};