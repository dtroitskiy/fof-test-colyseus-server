function calculate(magicalResistance, armor, isCrit)
	local critFactor = isCrit and 5 or 10
	return magicalResistance * critFactor + armor
end
