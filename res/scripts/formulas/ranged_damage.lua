require "math"
function calculate(weaponTypeName, strength, attack, ammoAttack, skill, random)
	local weaponTypeDivider = 1
	if weaponTypeName == "bow" then
		weaponTypeDivider = 4
	elseif weaponTypeName == "crossbow" then
		weaponTypeDivider = 3
	end
	return (strength * attack / weaponTypeDivider + ammoAttack) * math.min(skill * 0.025 + 0.45 + 0.55 * random, 1)
end

