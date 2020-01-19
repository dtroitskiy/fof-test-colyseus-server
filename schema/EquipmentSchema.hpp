// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.23
// 
#ifndef __SCHEMA_CODEGEN_EQUIPMENTSCHEMA_H__
#define __SCHEMA_CODEGEN_EQUIPMENTSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>



using namespace colyseus::schema;


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
	inline uint32_t getUint32(string field)
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

	inline void setUint32(string field, uint32_t value)
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


#endif
