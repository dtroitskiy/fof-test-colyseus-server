// 
// THIS FILE HAS BEEN GENERATED AUTOMATICALLY
// DO NOT CHANGE IT MANUALLY UNLESS YOU KNOW WHAT YOU'RE DOING
// 
// GENERATED USING @colyseus/schema 0.5.34
// 
#ifndef __SCHEMA_CODEGEN_TALENTSCHEMA_H__
#define __SCHEMA_CODEGEN_TALENTSCHEMA_H__ 1

#include "schema.h"
#include <typeinfo>
#include <typeindex>



using namespace colyseus::schema;


class TalentSchema : public Schema {
public:
	 uint32_t id = 0;
	 uint8_t level = 0;

	TalentSchema() {
		this->_indexes = {{0, "id"}, {1, "level"}};
		this->_types = {{0, "uint32"}, {1, "uint8"}};
		this->_childPrimitiveTypes = {};
		this->_childSchemaTypes = {};
	}

	virtual ~TalentSchema() {
		
	}

protected:
	inline uint32_t getUint32(const string &field)
	{
		if (field == "id")
		{
			return this->id;

		}
		return Schema::getUint32(field);
	}

	inline void setUint32(const string &field, uint32_t value)
	{
		if (field == "id")
		{
			this->id = value;
			return;

		}
		return Schema::setUint32(field, value);
	}
	inline uint8_t getUint8(const string &field)
	{
		if (field == "level")
		{
			return this->level;

		}
		return Schema::getUint8(field);
	}

	inline void setUint8(const string &field, uint8_t value)
	{
		if (field == "level")
		{
			this->level = value;
			return;

		}
		return Schema::setUint8(field, value);
	}


};


#endif
