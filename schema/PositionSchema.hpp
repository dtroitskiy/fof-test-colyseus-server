// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.23
// 
#ifndef __SCHEMA_CODEGEN_POSITIONSCHEMA_H__
#define __SCHEMA_CODEGEN_POSITIONSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>



using namespace colyseus::schema;


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
	inline float32_t getFloat32(string field)
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

	inline void setFloat32(string field, float32_t value)
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


#endif
