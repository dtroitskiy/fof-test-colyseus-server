#ifndef _MULTIPLAYER_SCHEMA_CLASSES_H_
#define _MULTIPLAYER_SCHEMA_CLASSES_H_

#include "colyseus/Serializer/schema.h"

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
	inline float32_t getFloat32(const string & field)
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

	inline void setFloat32(const string & field, float32_t value)
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

class EquipmentSchema : public Schema {
public:
	 uint32_t id = 0;
	 uint32_t primaryWeaponID = 0;
	 uint32_t secondaryWeaponID = 0;
	 uint32_t shieldID = 0;
	 uint32_t wandID = 0;
	 uint32_t primaryAmmoID = 0;
	 uint32_t secondaryAmmoID = 0;
	 uint32_t headID = 0;
	 uint32_t shouldersID = 0;
	 uint32_t handsID = 0;
	 uint32_t chestID = 0;
	 uint32_t legsID = 0;
	 uint32_t feetID = 0;
	 uint32_t gadget1ID = 0;
	 uint32_t gadget2ID = 0;
	 uint32_t gadget3ID = 0;
	 uint32_t gadget4ID = 0;

	EquipmentSchema() {
		this->_indexes = {{0, "id"}, {1, "primaryWeaponID"}, {2, "secondaryWeaponID"}, {3, "shieldID"}, {4, "wandID"}, {5, "primaryAmmoID"}, {6, "secondaryAmmoID"}, {7, "headID"}, {8, "shouldersID"}, {9, "handsID"}, {10, "chestID"}, {11, "legsID"}, {12, "feetID"}, {13, "gadget1ID"}, {14, "gadget2ID"}, {15, "gadget3ID"}, {16, "gadget4ID"}};
		this->_types = {{0, "uint32"}, {1, "uint32"}, {2, "uint32"}, {3, "uint32"}, {4, "uint32"}, {5, "uint32"}, {6, "uint32"}, {7, "uint32"}, {8, "uint32"}, {9, "uint32"}, {10, "uint32"}, {11, "uint32"}, {12, "uint32"}, {13, "uint32"}, {14, "uint32"}, {15, "uint32"}, {16, "uint32"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~EquipmentSchema() {
		
	}

protected:
	inline uint32_t getUint32(const string & field)
	{
		if (field == "id")
		{
			return this->id;

		} else if (field == "primaryWeaponID")
		{
			return this->primaryWeaponID;

		} else if (field == "secondaryWeaponID")
		{
			return this->secondaryWeaponID;

		} else if (field == "shieldID")
		{
			return this->shieldID;

		} else if (field == "wandID")
		{
			return this->wandID;

		} else if (field == "primaryAmmoID")
		{
			return this->primaryAmmoID;

		} else if (field == "secondaryAmmoID")
		{
			return this->secondaryAmmoID;

		} else if (field == "headID")
		{
			return this->headID;

		} else if (field == "shouldersID")
		{
			return this->shouldersID;

		} else if (field == "handsID")
		{
			return this->handsID;

		} else if (field == "chestID")
		{
			return this->chestID;

		} else if (field == "legsID")
		{
			return this->legsID;

		} else if (field == "feetID")
		{
			return this->feetID;

		} else if (field == "gadget1ID")
		{
			return this->gadget1ID;

		} else if (field == "gadget2ID")
		{
			return this->gadget2ID;

		} else if (field == "gadget3ID")
		{
			return this->gadget3ID;

		} else if (field == "gadget4ID")
		{
			return this->gadget4ID;

		}
		return Schema::getUint32(field);
	}

	inline void setUint32(const string & field, uint32_t value)
	{
		if (field == "id")
		{
			this->id = value;
			return;

		} else if (field == "primaryWeaponID")
		{
			this->primaryWeaponID = value;
			return;

		} else if (field == "secondaryWeaponID")
		{
			this->secondaryWeaponID = value;
			return;

		} else if (field == "shieldID")
		{
			this->shieldID = value;
			return;

		} else if (field == "wandID")
		{
			this->wandID = value;
			return;

		} else if (field == "primaryAmmoID")
		{
			this->primaryAmmoID = value;
			return;

		} else if (field == "secondaryAmmoID")
		{
			this->secondaryAmmoID = value;
			return;

		} else if (field == "headID")
		{
			this->headID = value;
			return;

		} else if (field == "shouldersID")
		{
			this->shouldersID = value;
			return;

		} else if (field == "handsID")
		{
			this->handsID = value;
			return;

		} else if (field == "chestID")
		{
			this->chestID = value;
			return;

		} else if (field == "legsID")
		{
			this->legsID = value;
			return;

		} else if (field == "feetID")
		{
			this->feetID = value;
			return;

		} else if (field == "gadget1ID")
		{
			this->gadget1ID = value;
			return;

		} else if (field == "gadget2ID")
		{
			this->gadget2ID = value;
			return;

		} else if (field == "gadget3ID")
		{
			this->gadget3ID = value;
			return;

		} else if (field == "gadget4ID")
		{
			this->gadget4ID = value;
			return;

		}
		return Schema::setUint32(field, value);
	}
};

class SpellSchema : public Schema {
public:
	 uint32_t id = 0;
	 uint32_t level = 0;

	SpellSchema() {
		this->_indexes = {{0, "id"}, {1, "level"}};
		this->_types = {{0, "uint32"}, {1, "uint32"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~SpellSchema() {
		
	}

protected:
	inline uint32_t getUint32(const string & field)
	{
		if (field == "id")
		{
			return this->id;

		} else if (field == "level")
		{
			return this->level;

		}
		return Schema::getUint32(field);
	}

	inline void setUint32(const string & field, uint32_t value)
	{
		if (field == "id")
		{
			this->id = value;
			return;

		} else if (field == "level")
		{
			this->level = value;
			return;

		}
		return Schema::setUint32(field, value);
	}
};

class TalentSchema : public Schema {
public:
	 uint32_t id = 0;
	 uint32_t level = 0;

	TalentSchema() {
		this->_indexes = {{0, "id"}, {1, "level"}};
		this->_types = {{0, "uint32"}, {1, "uint32"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~TalentSchema() {
		
	}

protected:
	inline uint32_t getUint32(const string & field)
	{
		if (field == "id")
		{
			return this->id;

		} else if (field == "level")
		{
			return this->level;

		}
		return Schema::getUint32(field);
	}

	inline void setUint32(const string & field, uint32_t value)
	{
		if (field == "id")
		{
			this->id = value;
			return;

		} else if (field == "level")
		{
			this->level = value;
			return;

		}
		return Schema::setUint32(field, value);
	}
};

class CombatDataSchema : public Schema {
public:
	 uint32_t creatureObjectID = 0;
	 uint32_t exp = 0;
	 uint32_t level = 0;
	 AbilitiesSchema *abilities = new AbilitiesSchema();
	 EquipmentSchema *equipment = new EquipmentSchema();
	 ArraySchema<SpellSchema*> *spells = new ArraySchema<SpellSchema*>();
	 ArraySchema<TalentSchema*> *talents = new ArraySchema<TalentSchema*>();

	CombatDataSchema() {
		this->_indexes = {{0, "creatureObjectID"}, {1, "exp"}, {2, "level"}, {3, "abilities"}, {4, "equipment"}, {5, "spells"}, {6, "talents"}};
		this->_types = {{0, "uint32"}, {1, "uint32"}, {2, "uint32"}, {3, "ref"}, {4, "ref"}, {5, "array"}, {6, "array"}};
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
	inline uint32_t getUint32(const string & field)
	{
		if (field == "creatureObjectID")
		{
			return this->creatureObjectID;

		} else if (field == "exp")
		{
			return this->exp;

		} else if (field == "level")
		{
			return this->level;

		}
		return Schema::getUint32(field);
	}

	inline void setUint32(const string & field, uint32_t value)
	{
		if (field == "creatureObjectID")
		{
			this->creatureObjectID = value;
			return;

		} else if (field == "exp")
		{
			this->exp = value;
			return;

		} else if (field == "level")
		{
			this->level = value;
			return;

		}
		return Schema::setUint32(field, value);
	}
	inline Schema* getRef(const string & field)
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

	inline void setRef(const string & field, Schema* value)
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
	inline ArraySchema<char*> * getArray(const string & field)
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

	inline void setArray(const string & field, ArraySchema<char*> * value)
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

class PositionSchema : public Schema {
public:
	 float32_t x = 0;
	 float32_t y = 0;
	 float32_t z = 0;

	PositionSchema() {
		this->_indexes = {{0, "x"}, {1, "y"}, {2, "z"}};
		this->_types = {{0, "float32"}, {1, "float32"}, {2, "float32"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~PositionSchema() {
		
	}

protected:
	inline float32_t getFloat32(const string & field)
	{
		if (field == "x")
		{
			return this->x;

		} else if (field == "y")
		{
			return this->y;

		} else if (field == "z")
		{
			return this->z;

		}
		return Schema::getFloat32(field);
	}

	inline void setFloat32(const string & field, float32_t value)
	{
		if (field == "x")
		{
			this->x = value;
			return;

		} else if (field == "y")
		{
			this->y = value;
			return;

		} else if (field == "z")
		{
			this->z = value;
			return;

		}
		return Schema::setFloat32(field, value);
	}
};

class DirectionSchema : public Schema {
public:
	 float32_t x = 0;
	 float32_t y = 0;

	DirectionSchema() {
		this->_indexes = {{0, "x"}, {1, "y"}};
		this->_types = {{0, "float32"}, {1, "float32"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~DirectionSchema() {
		
	}

protected:
	inline float32_t getFloat32(const string & field)
	{
		if (field == "x")
		{
			return this->x;

		} else if (field == "y")
		{
			return this->y;

		}
		return Schema::getFloat32(field);
	}

	inline void setFloat32(const string & field, float32_t value)
	{
		if (field == "x")
		{
			this->x = value;
			return;

		} else if (field == "y")
		{
			this->y = value;
			return;

		}
		return Schema::setFloat32(field, value);
	}
};

class SelectedEquipmentSchema : public Schema {
public:
	 bool isPrimary = false;

	SelectedEquipmentSchema() {
		this->_indexes = {{0, "isPrimary"}};
		this->_types = {{0, "boolean"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~SelectedEquipmentSchema() {
		
	}

protected:
	inline bool getBoolean(const string & field)
	{
		if (field == "isPrimary")
		{
			return this->isPrimary;

		}
		return Schema::getBoolean(field);
	}

	inline void setBoolean(const string & field, bool value)
	{
		if (field == "isPrimary")
		{
			this->isPrimary = value;
			return;

		}
		return Schema::setBoolean(field, value);
	}
};

class ChangingAbilitySchema : public Schema {
public:
	 float32_t current = 0;
	 float32_t total = 0;
	 uint8_t changeType = 0;

	ChangingAbilitySchema() {
		this->_indexes = {{0, "current"}, {1, "total"}, {2, "changeType"}};
		this->_types = {{0, "float32"}, {1, "float32"}, {2, "uint8"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~ChangingAbilitySchema() {
		
	}

protected:
	inline float32_t getFloat32(const string & field)
	{
		if (field == "current")
		{
			return this->current;

		} else if (field == "total")
		{
			return this->total;

		}
		return Schema::getFloat32(field);
	}

	inline void setFloat32(const string & field, float32_t value)
	{
		if (field == "current")
		{
			this->current = value;
			return;

		} else if (field == "total")
		{
			this->total = value;
			return;

		}
		return Schema::setFloat32(field, value);
	}
	inline uint8_t getUint8(const string & field)
	{
		if (field == "changeType")
		{
			return this->changeType;

		}
		return Schema::getUint8(field);
	}

	inline void setUint8(const string & field, uint8_t value)
	{
		if (field == "changeType")
		{
			this->changeType = value;
			return;

		}
		return Schema::setUint8(field, value);
	}
};

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
	inline string getString(const string & field)
	{
		if (field == "id")
		{
			return this->id;

		}
		return Schema::getString(field);
	}

	inline void setString(const string & field, string value)
	{
		if (field == "id")
		{
			this->id = value;
			return;

		}
		return Schema::setString(field, value);
	}
	inline Schema* getRef(const string & field)
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

	inline void setRef(const string & field, Schema* value)
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
	inline MapSchema<char*> * getMap(const string & field)
	{
		if (field == "creatures")
		{
			return (MapSchema<char*> *)this->creatures;

		}
		return Schema::getMap(field);
	}

	inline void setMap(const string & field, MapSchema<char*> * value)
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

#endif // _MULTIPLAYER_SCHEMA_CLASSES_H_

