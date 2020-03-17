// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.34
// 
#ifndef __SCHEMA_CODEGEN_COMBATSCHEMA_H__
#define __SCHEMA_CODEGEN_COMBATSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>

#include "CreatureSchema.hpp"

using namespace colyseus::schema;


class CombatSchema : public Schema {
public:
	 MapSchema<CreatureSchema*> *creatures = new MapSchema<CreatureSchema*>();

	CombatSchema() {
		this->_indexes = {{0, "creatures"}};
		this->_types = {{0, "map"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {{0, typeid(CreatureSchema)}};
	}

	virtual ~CombatSchema() {
		delete this->creatures;
	}

protected:
	inline MapSchema<char*> * getMap(const string &field)
	{
		if (field == "creatures")
		{
			return (MapSchema<char*> *)this->creatures;

		}
		return Schema::getMap(field);
	}

	inline void setMap(const string &field, MapSchema<char*> * value)
	{
		if (field == "creatures")
		{
			this->creatures = (MapSchema<CreatureSchema*> *)value;
			return;

		}
		return Schema::setMap(field, value);
	}

	inline Schema* createInstance(std::type_index type) {
		if (type == typeid(CreatureSchema))
		{
			return new CreatureSchema();

		}
		return Schema::createInstance(type);
	}
};


#endif
