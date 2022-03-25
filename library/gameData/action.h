#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "baseObject.h"

class GAMEDATA_EXPORT action : public baseObject
{
public:
	action();
	~action();

	void SetSubject(baseObject* sub);
	baseObject* GetSubject();

	void SetObject(baseObject* obj);
	baseObject* GetObject();

	virtual bool DoAction() = 0;

protected:
	int m_count;
	baseObject* m_subject;
	baseObject* m_object;
};
