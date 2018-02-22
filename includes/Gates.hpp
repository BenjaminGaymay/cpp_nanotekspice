/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Gates
*/

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

	std::map<Gate, std::function<Tristate(Pin *, Pin *)>> fct_gates =
	{
		{OR, gate_or},
		{NOR, gate_nor},
		{AND, gate_and},
		{NAND, gate_nand},
		{GET_OUTPUT, get_output}
	};
}
