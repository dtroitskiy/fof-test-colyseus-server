// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.23
// 
#ifndef __SCHEMA_CODEGEN_COMBATDATASCHEMA_H__
#define __SCHEMA_CODEGEN_COMBATDATASCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>

#include "AbilitiesSchema.hpp"
#include "EquipmentSchema.hpp"
#include "SpellSchema.hpp"
#include "TalentSchema.hpp"

using namespace colyseus::schema;


class CombatDataSchema : public Schema {
public:
	 uint32_t creatureObjectID = 0;
	 uint32_t exp = 0;
	 uint8_t level = 0;
	 AbilitiesSchema *abilities = new AbilitiesSchema();
	 EquipmentSchema *equipment = new EquipmentSchema();
	 ArraySchema<SpellSchema*> *spells = new ArraySchema<SpellSchema*>();
	 ArraySchema<TalentSchema*> *talents = new ArraySchema<TalentSchema*>();

	CombatDataSchema() {
		this->_indexes = {{0, "creatureObjectID"}, {1, "exp"}, {2, "level"}, {3, "abilities"}, {4, "equipment"}, {5, "spells"}, {6, "talents"}};
		this->_types = {{0, "uint32"}, {1, "uint32"}, {2, "uint8"}, {3, "ref"}, {4, "ref"}, {5, "array"}, {6, "array"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {{3, typeid(AbilitiesSchema)}, {4, typeid(EquipmentSchema)}, {5, typeid(SpellSchema)}, {6, typeid(TalentSchema)}};
	}

	virtual ~CombatDataSchema() {
		delete this->abilities;
		delete this->equipment;
		delete this->spells;
		delete this->talents;
	}

protected:
	inline uint32_t getUint32(string field)
	{
		if (field == "creatureObjectID")
		{
			return this->creatureObjectID;

		} else if (field == "exp")
		{
			return this->exp;

		}
		return Schema::getUint32(field);
	}

	inline void setUint32(string field, uint32_t value)
	{
		if (field == "creatureObjectID")
		{
			this->creatureObjectID = value;
			return;

		} else if (field == "exp")
		{
			this->exp = value;
			return;

		}
		return Schema::setUint32(field, value);
	}
	inline uint8_t getUint8(string field)
	{
		if (field == "level")
		{
			return this->level;

		}
		return Schema::getUint8(field);
	}

	inline void setUint8(string field, uint8_t value)
	{
		if (field == "level")
		{
			this->level = value;
			return;

		}
		return Schema::setUint8(field, value);
	}
	inline Schema* getRef(string field)
	{
		if (field == "abilities")
		{
			return this->abilities;

		} else if (field == "equipment")
		{
			return this->equipment;

		}
		return Schema::getRef(field);
	}

	inline void setRef(string field, Schema* value)
	{
		if (field == "abilities")
		{
			this->abilities = (AbilitiesSchema*)value;
			return;

		} else if (field == "equipment")
		{
			this->equipment = (EquipmentSchema*)value;
			return;

		}
		return Schema::setRef(field, value);
	}
	inline ArraySchema<char*> * getArray(string field)
	{
		if (field == "spells")
		{
			return (ArraySchema<char*> *)this->spells;

		} else if (field == "talents")
		{
			return (ArraySchema<char*> *)this->talents;

		}
		return Schema::getArray(field);
	}

	inline void setArray(string field, ArraySchema<char*> * value)
	{
		if (field == "spells")
		{
			this->spells = (ArraySchema<SpellSchema*> *)value;
			return;

		} else if (field == "talents")
		{
			this->talents = (ArraySchema<TalentSchema*> *)value;
			return;

		}
		return Schema::setArray(field, value);
	}

	inline Schema* createInstance(std::type_index type) {
		if (type == typeid(AbilitiesSchema))
		{
			return new AbilitiesSchema();

		} else if (type == typeid(EquipmentSchema))
		{
			return new EquipmentSchema();

		} else if (type == typeid(SpellSchema))
		{
			return new SpellSchema();

		} else if (type == typeid(TalentSchema))
		{
			return new TalentSchema();

		}
		return Schema::createInstance(type);
	}
};


#endif
