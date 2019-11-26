require "math"
function calculate(strength, attack, skill, random)
	return strength * attack / 4 * math.min(skill * 0.025 + 0.45 + 0.55 * random, 1)
end
