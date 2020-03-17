// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.34
// 
#ifndef __SCHEMA_CODEGEN_ABILITIESSCHEMA_H__
#define __SCHEMA_CODEGEN_ABILITIESSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>



using namespace colyseus::schema;


class AbilitiesSchema : public Schema {
public:
	 float32_t HP = 0;
	 float32_t MP = 0;
	 float32_t magicalAbility = 0;
	 float32_t moveSpeed = 0;
	 float32_t exhaustionTime = 0;
	 float32_t oneHandedWeapon = 0;
	 float32_t twoHandedWeapon = 0;
	 float32_t strength = 0;
	 float32_t HPRegen = 0;
	 float32_t MPRegen = 0;
	 float32_t bow = 0;
	 float32_t crossbow = 0;
	 float32_t throwing = 0;
	 float32_t shielding = 0;
	 float32_t magicalResistance = 0;
	 float32_t defense = 0;
	 float32_t capacity = 0;

	AbilitiesSchema() {
		this->_indexes = {{0, "HP"}, {1, "MP"}, {2, "magicalAbility"}, {3, "moveSpeed"}, {4, "exhaustionTime"}, {5, "oneHandedWeapon"}, {6, "twoHandedWeapon"}, {7, "strength"}, {8, "HPRegen"}, {9, "MPRegen"}, {10, "bow"}, {11, "crossbow"}, {12, "throwing"}, {13, "shielding"}, {14, "magicalResistance"}, {15, "defense"}, {16, "capacity"}};
		this->_types = {{0, "float32"}, {1, "float32"}, {2, "float32"}, {3, "float32"}, {4, "float32"}, {5, "float32"}, {6, "float32"}, {7, "float32"}, {8, "float32"}, {9, "float32"}, {10, "float32"}, {11, "float32"}, {12, "float32"}, {13, "float32"}, {14, "float32"}, {15, "float32"}, {16, "float32"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~AbilitiesSchema() {
		
	}

protected:
	inline float32_t getFloat32(const string &field)
	{
		if (field == "HP")
		{
			return this->HP;

		} else if (field == "MP")
		{
			return this->MP;

		} else if (field == "magicalAbility")
		{
			return this->magicalAbility;

		} else if (field == "moveSpeed")
		{
			return this->moveSpeed;

		} else if (field == "exhaustionTime")
		{
			return this->exhaustionTime;

		} else if (field == "oneHandedWeapon")
		{
			return this->oneHandedWeapon;

		} else if (field == "twoHandedWeapon")
		{
			return this->twoHandedWeapon;

		} else if (field == "strength")
		{
			return this->strength;

		} else if (field == "HPRegen")
		{
			return this->HPRegen;

		} else if (field == "MPRegen")
		{
			return this->MPRegen;

		} else if (field == "bow")
		{
			return this->bow;

		} else if (field == "crossbow")
		{
			return this->crossbow;

		} else if (field == "throwing")
		{
			return this->throwing;

		} else if (field == "shielding")
		{
			return this->shielding;

		} else if (field == "magicalResistance")
		{
			return this->magicalResistance;

		} else if (field == "defense")
		{
			return this->defense;

		} else if (field == "capacity")
		{
			return this->capacity;

		}
		return Schema::getFloat32(field);
	}

	inline void setFloat32(const string &field, float32_t value)
	{
		if (field == "HP")
		{
			this->HP = value;
			return;

		} else if (field == "MP")
		{
			this->MP = value;
			return;

		} else if (field == "magicalAbility")
		{
			this->magicalAbility = value;
			return;

		} else if (field == "moveSpeed")
		{
			this->moveSpeed = value;
			return;

		} else if (field == "exhaustionTime")
		{
			this->exhaustionTime = value;
			return;

		} else if (field == "oneHandedWeapon")
		{
			this->oneHandedWeapon = value;
			return;

		} else if (field == "twoHandedWeapon")
		{
			this->twoHandedWeapon = value;
			return;

		} else if (field == "strength")
		{
			this->strength = value;
			return;

		} else if (field == "HPRegen")
		{
			this->HPRegen = value;
			return;

		} else if (field == "MPRegen")
		{
			this->MPRegen = value;
			return;

		} else if (field == "bow")
		{
			this->bow = value;
			return;

		} else if (field == "crossbow")
		{
			this->crossbow = value;
			return;

		} else if (field == "throwing")
		{
			this->throwing = value;
			return;

		} else if (field == "shielding")
		{
			this->shielding = value;
			return;

		} else if (field == "magicalResistance")
		{
			this->magicalResistance = value;
			return;

		} else if (field == "defense")
		{
			this->defense = value;
			return;

		} else if (field == "capacity")
		{
			this->capacity = value;
			return;

		}
		return Schema::setFloat32(field, value);
	}


};


#endif
