import { Schema, ArraySchema, MapSchema, type } from "@colyseus/schema";

class AbilitiesSchema extends Schema
{
	@type('float32')
	HP: nubmer;

	@type('float32')
	MP: number;

	@type('float32')
	magicalAbility: nubmer;

	@type('float32')
	moveSpeed: nubmer;

	@type('float32')
	exhaustionTime: nubmer;

	@type('float32')
	oneHandedWeapon: nubmer;

	@type('float32')
	twoHandedWeapon: nubmer;

	@type('float32')
	strength: nubmer;
	
	@type('float32')
	HPRegen: number;

	@type('float32')
	MPRegen: number;
	
	@type('float32')
	bow: number;

	@type('float32')
	crossbow: number;

	@type('float32')
	throwing: number;

	@type('float32')
	shielding: number;

	@type('float32')
	magicalResistance: number;

	@type('float32')
	defense: number;

	@type('float32')
	capacity: number;

	constructor(abilities: object)
	{
		super();
		for (let i in abilities)
		{
			this[i] = abilities[i];
		}
	}
}

class EquipmentSchema extends Schema
{
	@type('uint32')
	id: number;

	@type('uint32')
	primaryWeaponID: number;

	@type('uint32')
	secondaryWeaponID: number;

	@type('uint32')
	shieldID: number;

	@type('uint32')
	wandID: number;

	@type('uint32')
	primaryAmmoID: number;
	
	@type('uint32')
	secondaryAmmoID: number;

	@type('uint32')
	headID: number;

	@type('uint32')
	shouldersID: number;

	@type('uint32')
	handsID: number;

	@type('uint32')
	chestID: number;

	@type('uint32')
	legsID: number;

	@type('uint32')
	feetID: number;

	@type('uint32')
	gadget1ID: number;

	@type('uint32')
	gadget2ID: number;

	@type('uint32')
	gadget3ID: number;

	@type('uint32')
	gadget4ID: number;

	constructor(equipment: object)
	{
		super();
		for (let i in equipment)
		{
			this[i] = equipment[i];
		}
	}
}

class SpellSchema extends Schema
{
	@type('uint32')
	id: number;

	@type('uint32')
	level: number;

	constructor(spell: object)
	{
		super();
		this.id = spell.id;
		this.level = spell.level;
	}
}

class TalentSchema extends Schema
{
	@type('uint32')
	id: number;

	@type('uint32')
	level: number;

	constructor(talent: object)
	{
		super();
		this.id = talent.id;
		this.level = talent.level;
	}
}

export class CombatDataSchema extends Schema
{
	@type('uint32')
	creatureObjectID: number;

	@type('uint32')
	exp: number;

	@type('uint8')
	level: number;

	@type(AbilitiesSchema)
	abilities: AbilitiesSchema;
	
	@type(EquipmentSchema)
	equipment: EquipmentSchema;

	@type([SpellSchema])
	spells: ArraySchema <SpellSchema>;
	
	@type([TalentSchema])
	talents: ArraySchema <TalentSchema>;

	constructor(combatData: object)
	{
		super();

		this.creatureObjectID = combatData.creatureObjectID;
		this.exp = combatData.exp;
		this.level = combatData.level;
		this.abilities = new AbilitiesSchema(combatData.abilities);
		this.equipment = new EquipmentSchema(combatData.equipment);
		this.spells = new ArraySchema <SpellSchema> ();
		for (let i = 0; i < combatData.spells.length; ++i)
		{
			this.spells.push(new SpellSchema(combatData.spells[i]));
		}
		this.talents = new ArraySchema <TalentSchema> ();
		for (let i = 0; i < combatData.talents.length; ++i)
		{
			this.talents.push(new TalentSchema(combatData.talents[i]));
		}
	}
}

export class PositionSchema extends Schema
{
	@type('float32')
	x: number;

	@type('float32')
	y: number;

	@type('uint8')
	z: number;

	constructor(x: number, y: number, z: number)
	{
		super();
		this.x = x;
		this.y = y;
		this.z = z;
	}
}

export class DirectionSchema extends Schema
{
	@type('float32')
	x: number;

	@type('float32')
	y: number;

	constructor(x: number, y: number)
	{
		super();
		this.x = x;
		this.y = y;
	}
}

export class SelectedEquipmentSchema extends Schema
{
	@type('boolean')
	isPrimary: boolean;

	constructor(isPrimary)
	{
		super();
		this.isPrimary = isPrimary;
	}
}

export class ChangingAbilitySchema extends Schema
{
	@type('float32')
	current: number;

	@type('float32')
	total: number;

	@type('uint8')
	changeType: number;

	constructor(current: number, total: number)
	{
		super();
		this.current = current;
		this.total = total;
	}
}

export class CreatureSchema extends Schema
{
	@type('string')
	id: string;

	@type(CombatDataSchema)
	combatData: CombatDataSchema;

	@type(PositionSchema)
	position: PositionSchema;

	lastValidPosition: PositionSchema;

	// this variable is not synced
	lastPositionValidationTime: number = 0;

	@type(DirectionSchema)
	movementDirection: DirectionSchema;

	@type(DirectionSchema)
	lookDirection: DirectionSchema;

	@type(SelectedEquipmentSchema)
	selectedWeapon: SelectedEquipmentSchema;

	@type(SelectedEquipmentSchema)
	selectedAmmo: SelectedEquipmentSchema;

	@type(ChangingAbilitySchema)
	HP: ChangingAbilitySchema;

	@type(ChangingAbilitySchema)
	MP: ChangingAbilitySchema;
}

export class CombatSchema extends Schema
{
	@type({ 'map': CreatureSchema })
	creatures = new MapSchema <CreatureSchema> ();
}
