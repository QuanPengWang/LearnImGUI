#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "uuid.h"
#include <vector>
#include <string>
#include <map>

// virtual class
class action;
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

	std::map<uuids::uuid, action*> GetInitiatives();
	std::map<uuids::uuid, action*> GetActionables();

protected:
	uuids::uuid m_id;
	std::string m_name;

	std::map<uuids::uuid, action*> m_initiatives;		// 主动性动作
	std::map<uuids::uuid, action*> m_actionables;		// 可被动动作
};