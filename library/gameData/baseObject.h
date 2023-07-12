#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "uuid.h"
#include <vector>
#include <string>

// virtual class
class GAMEDATA_EXPORT baseObject
{
public:
	baseObject();
	~baseObject();

	void SetID(const uuids::uuid& id);
	uuids::uuid GetID();

	void SetID(const std::string& id);
	std::string GetIDString() const;

	void SetName(const std::string& name);
	std::string GetName();

protected:
	uuids::uuid m_id;
	std::string m_name;
};