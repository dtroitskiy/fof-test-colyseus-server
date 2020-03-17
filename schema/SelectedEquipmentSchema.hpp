// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.34
// 
#ifndef __SCHEMA_CODEGEN_SELECTEDEQUIPMENTSCHEMA_H__
#define __SCHEMA_CODEGEN_SELECTEDEQUIPMENTSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>



using namespace colyseus::schema;


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
	inline bool getBoolean(const string &field)
	{
		if (field == "isPrimary")
		{
			return this->isPrimary;

		}
		return Schema::getBoolean(field);
	}

	inline void setBoolean(const string &field, bool value)
	{
		if (field == "isPrimary")
		{
			this->isPrimary = value;
			return;

		}
		return Schema::setBoolean(field, value);
	}


};


#endif
