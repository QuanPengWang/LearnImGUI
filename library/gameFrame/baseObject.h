#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include <vector>
#include <string>

// virtual class
class GAMEFRAME_EXPORT baseObject
{
public:
	baseObject();
	~baseObject();

	void SetID(const std::string& id);
	std::string GetID();

	void SetName(const std::string& name);
	std::string GetName();

private:
	std::string m_id;
	std::string m_name;
};