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
	Tristate gate_and(std::vector<Pin *>);
	Tristate gate_nand(std::vector<Pin *>);
	Tristate gate_or(std::vector<Pin *>);
	Tristate gate_nor(std::vector<Pin *>);

	std::map<Gate, std::function<Tristate(std::vector<Pin *>)>> fct_gates =
	{
		{OR, gate_or},
		{NOR, gate_nor},
		{AND, gate_and},
		{NAND, gate_nand}
	};
}
