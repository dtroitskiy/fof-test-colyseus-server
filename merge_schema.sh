cat schema/AbilitiesSchema.hpp schema/EquipmentSchema.hpp schema/SpellSchema.hpp schema/TalentSchema.hpp schema/CombatDataSchema.hpp schema/PositionSchema.hpp \
    schema/DirectionSchema.hpp schema/SelectedEquipmentSchema.hpp schema/ChangingAbilitySchema.hpp schema/CreatureSchema.hpp schema/CombatSchema.hpp > schema/MultiplayerSchemaClasses.h
sed -i -E "s/^\/\/.*$|^#.*$|^using.*$//gm" schema/MultiplayerSchemaClasses.h
cat -s schema/MultiplayerSchemaClasses.h > schema/MultiplayerSchemaClassesStripped.h
rm schema/MultiplayerSchemaClasses.h
mv schema/MultiplayerSchemaClassesStripped.h schema/MultiplayerSchemaClasses.h
sed -i '1 i\#ifndef _MULTIPLAYER_SCHEMA_CLASSES_\n#define _MULTIPLAYER_SCHEMA_CLASSES_\n\n#include "colyseus/Serializer/schema.h"\n\nusing namespace colyseus::schema;' schema/MultiplayerSchemaClasses.h
sed -i "\$a#endif // _MULTIPLAYER_SCHEMA_CLASSES_\n" schema/MultiplayerSchemaClasses.h
