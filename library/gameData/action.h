#pragma once
#pragma warning(disable:4251)
#include "gameDatalibExport.h"
#include "baseObject.h"
#include "substance.h"

class GAMEDATA_EXPORT action : public baseObject
{
public:
	action();
	~action();

	// 动作对象
	void SetSubject(substance* sub);
	substance* GetSubject();

	// 动作发起者
	void SetObject(substance* obj);
	substance* GetObject();

	virtual bool DoAction() = 0;

protected:
	int m_count;
	substance* m_subject;
	substance* m_object;
};
