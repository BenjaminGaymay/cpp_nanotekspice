//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Gates
//

#pragma once

#include <map>
#include <functional>
#include "Component.hpp"

namespace nts {
	Tristate gate_and(Pin *, Pin *);
	Tristate gate_nand(Pin *, Pin *);
	Tristate gate_or(Pin *, Pin *);
	Tristate gate_nor(Pin *, Pin *);
	Tristate get_output(Pin *, Pin *);

	extern std::map<Gate, std::function<Tristate(Pin *, Pin *)>> fct_gates;
}
