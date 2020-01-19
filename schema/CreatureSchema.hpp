// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.23
// 
#ifndef __SCHEMA_CODEGEN_CREATURESCHEMA_H__
#define __SCHEMA_CODEGEN_CREATURESCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>

#include "CombatDataSchema.hpp"
#include "PositionSchema.hpp"
#include "DirectionSchema.hpp"
#include "SelectedEquipmentSchema.hpp"
#include "ChangingAbilitySchema.hpp"

using namespace colyseus::schema;


class CreatureSchema : public Schema {
public:
	 string id = "";
	 CombatDataSchema *combatData = new CombatDataSchema();
	 PositionSchema *position = new PositionSchema();
	 DirectionSchema *movementDirection = new DirectionSchema();
	 DirectionSchema *lookDirection = new DirectionSchema();
	 SelectedEquipmentSchema *selectedWeapon = new SelectedEquipmentSchema();
	 SelectedEquipmentSchema *selectedAmmo = new SelectedEquipmentSchema();
	 ChangingAbilitySchema *HP = new ChangingAbilitySchema();
	 ChangingAbilitySchema *MP = new ChangingAbilitySchema();

	CreatureSchema() {
		this->_indexes = {{0, "id"}, {1, "combatData"}, {2, "position"}, {3, "movementDirection"}, {4, "lookDirection"}, {5, "selectedWeapon"}, {6, "selectedAmmo"}, {7, "HP"}, {8, "MP"}};
		this->_types = {{0, "string"}, {1, "ref"}, {2, "ref"}, {3, "ref"}, {4, "ref"}, {5, "ref"}, {6, "ref"}, {7, "ref"}, {8, "ref"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {{1, typeid(CombatDataSchema)}, {2, typeid(PositionSchema)}, {3, typeid(DirectionSchema)}, {4, typeid(DirectionSchema)}, {5, typeid(SelectedEquipmentSchema)}, {6, typeid(SelectedEquipmentSchema)}, {7, typeid(ChangingAbilitySchema)}, {8, typeid(ChangingAbilitySchema)}};
	}

	virtual ~CreatureSchema() {
		delete this->combatData;
		delete this->position;
		delete this->movementDirection;
		delete this->lookDirection;
		delete this->selectedWeapon;
		delete this->selectedAmmo;
		delete this->HP;
		delete this->MP;
	}

protected:
	inline string getString(string field)
	{
		if (field == "id")
		{
			return this->id;

		}
		return Schema::getString(field);
	}

	inline void setString(string field, string value)
	{
		if (field == "id")
		{
			this->id = value;
			return;

		}
		return Schema::setString(field, value);
	}
	inline Schema* getRef(string field)
	{
		if (field == "combatData")
		{
			return this->combatData;

		} else if (field == "position")
		{
			return this->position;

		} else if (field == "movementDirection")
		{
			return this->movementDirection;

		} else if (field == "lookDirection")
		{
			return this->lookDirection;

		} else if (field == "selectedWeapon")
		{
			return this->selectedWeapon;

		} else if (field == "selectedAmmo")
		{
			return this->selectedAmmo;

		} else if (field == "HP")
		{
			return this->HP;

		} else if (field == "MP")
		{
			return this->MP;

		}
		return Schema::getRef(field);
	}

	inline void setRef(string field, Schema* value)
	{
		if (field == "combatData")
		{
			this->combatData = (CombatDataSchema*)value;
			return;

		} else if (field == "position")
		{
			this->position = (PositionSchema*)value;
			return;

		} else if (field == "movementDirection")
		{
			this->movementDirection = (DirectionSchema*)value;
			return;

		} else if (field == "lookDirection")
		{
			this->lookDirection = (DirectionSchema*)value;
			return;

		} else if (field == "selectedWeapon")
		{
			this->selectedWeapon = (SelectedEquipmentSchema*)value;
			return;

		} else if (field == "selectedAmmo")
		{
			this->selectedAmmo = (SelectedEquipmentSchema*)value;
			return;

		} else if (field == "HP")
		{
			this->HP = (ChangingAbilitySchema*)value;
			return;

		} else if (field == "MP")
		{
			this->MP = (ChangingAbilitySchema*)value;
			return;

		}
		return Schema::setRef(field, value);
	}

	inline Schema* createInstance(std::type_index type) {
		if (type == typeid(CombatDataSchema))
		{
			return new CombatDataSchema();

		} else if (type == typeid(PositionSchema))
		{
			return new PositionSchema();

		} else if (type == typeid(DirectionSchema))
		{
			return new DirectionSchema();

		} else if (type == typeid(SelectedEquipmentSchema))
		{
			return new SelectedEquipmentSchema();

		} else if (type == typeid(ChangingAbilitySchema))
		{
			return new ChangingAbilitySchema();

		}
		return Schema::createInstance(type);
	}
};


#endif
