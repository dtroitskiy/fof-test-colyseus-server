require "math"
function calculate(magicalAbility, spellValue, materialStatus, random, is3x3)
	local value = magicalAbility * 0.33 * spellValue * 0.5 * math.min(materialStatus * 0.05 + 0.45 + 0.55 * random, 1) / 2
	if is3x3 then
		value = value / 2
	end
	return value;
end
