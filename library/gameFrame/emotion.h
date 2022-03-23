#pragma once
#pragma warning(disable:4251)
#include "gameFramelibExport.h"
#include "baseObject.h"

class GAMEFRAME_EXPORT emotion : public baseObject
{
public:
	emotion();
	~emotion();

	void SetValue(const double& v);
	double GetValue();

	void SetName(const std::string& name);
	std::string GetName();

	void SetDescription(const std::string& des);
	std::string GetDescription();

protected:
	// 整体上来讲，id < 0 ,不好的心情
	// 0 < id ,好心情
	double m_value;
	std::string m_name;
	std::string m_description;
};