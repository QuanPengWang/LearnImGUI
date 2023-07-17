#include "baseObject.h"
#include <iostream>

baseObject::baseObject()
{
	std::random_device rd;
	auto seed_data = std::array<int, std::mt19937::state_size> {};
	std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
	std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
	std::mt19937 generator(seq);
	uuids::uuid_random_generator gen{generator};

	m_id = gen();

	std::cout << "Create UUID : " << uuids::to_string(m_id) << std::endl;
}

baseObject::~baseObject()
{
}

void baseObject::SetID(const std::string& id)
{
	m_id = uuids::uuid::from_string(id).value();
}

std::string baseObject::GetIDString() const
{
	return uuids::to_string(m_id);
}

void baseObject::SetID(const uuids::uuid& id)
{
	m_id = id;
}

uuids::uuid baseObject::GetID()
{
	return m_id;
}

void baseObject::SetName(const std::string& name)
{
	m_name = name;
}

std::string baseObject::GetName()
{
	return m_name;
}

std::map<uuids::uuid, action*> baseObject::GetInitiatives()
{
	return m_initiatives;
}

std::map<uuids::uuid, action*> baseObject::GetActionables()
{
	return m_actionables;
}
