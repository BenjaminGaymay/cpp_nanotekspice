/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Gates
*/

#pragma once

#include "Component.hpp"

namespace nts {
	Tristate gate_and(std::vector<Pin *>);
	Tristate gate_nand(std::vector<Pin *>);
	Tristate gate_or(std::vector<Pin *>);
	Tristate gate_nor(std::vector<Pin *>);
}
