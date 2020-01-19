// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.23
// 
#ifndef __SCHEMA_CODEGEN_CHANGINGABILITYSCHEMA_H__
#define __SCHEMA_CODEGEN_CHANGINGABILITYSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>



using namespace colyseus::schema;


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
	inline float32_t getFloat32(string field)
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

	inline void setFloat32(string field, float32_t value)
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
	inline uint8_t getUint8(string field)
	{
		if (field == "changeType")
		{
			return this->changeType;

		}
		return Schema::getUint8(field);
	}

	inline void setUint8(string field, uint8_t value)
	{
		if (field == "changeType")
		{
			this->changeType = value;
			return;

		}
		return Schema::setUint8(field, value);
	}


};


#endif
