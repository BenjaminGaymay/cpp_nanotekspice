//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Gates
//

#include <functional>
#include "Component.hpp"

namespace nts {
	Tristate gate_and(std::vector<Pin *> &deps)
	{
		auto state1 = deps[0]->_state;
		auto state2 = deps[1]->_state;

		if (state1 == FALSE or state2 == FALSE)
			return FALSE;
		if (state1 == UNDEFINED or state2 == UNDEFINED)
			return UNDEFINED;
		return TRUE;
	}

	Tristate gate_nand(std::vector<Pin *> &deps)
	{
		auto state = gate_and(deps);

		if (state == UNDEFINED)
			return UNDEFINED;
		return state == TRUE ? FALSE : TRUE;
	}

	Tristate gate_or(std::vector<Pin *> &deps)
	{
		auto state1 = deps[0]->_state;
		auto state2 = deps[1]->_state;

		if (state1 == TRUE or state2 == TRUE)
			return TRUE;
		if (state1 == UNDEFINED or state2 == UNDEFINED)
			return UNDEFINED;
		return FALSE;
	}

	Tristate gate_nor(std::vector<Pin *> &deps)
	{
		auto state = gate_or(deps);

		return state == TRUE ? FALSE : TRUE;
	}

	Tristate gate_xor(std::vector<Pin *> &deps)
	{
		auto state1 = deps[0]->_state;
		auto state2 = deps[1]->_state;

		if (state1 == UNDEFINED or state2 == UNDEFINED)
			return UNDEFINED;
		return state1 != state2 ? TRUE : FALSE;
	}

	Tristate gate_xnor(std::vector<Pin *> &deps)
	{
		auto state = gate_xor(deps);

		if (state == UNDEFINED)
			return UNDEFINED;
		return state == TRUE ? FALSE : TRUE;
	}

	Tristate gate_inverted(std::vector<Pin *> &deps)
	{
		auto state = deps[0]->_state;

		if (state == UNDEFINED)
			return UNDEFINED;
		return state == TRUE ? TRUE : FALSE;
	}

	Tristate get_output(std::vector<Pin *> &deps)
	{
		auto input = deps[0];

		return input->_state;
	}

	Tristate gate_sum(std::vector<Pin *> deps)
	{
		return TRUE;
	}

	std::map<Gate, std::function<Tristate(std::vector<Pin *>)>> fct_gates =
	{
		{OR, gate_or},
		{NOR, gate_nor},
		{AND, gate_and},
		{NAND, gate_nand},
		{XOR, gate_xor},
		{XNOR, gate_xnor},
		{INVERTED, gate_inverted},
		{SUM, gate_sum},
		{GET_OUTPUT, get_output}
	};
}
