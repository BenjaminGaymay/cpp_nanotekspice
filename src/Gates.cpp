//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Gates
//

#include <functional>
#include "Component.hpp"

namespace nts {
	Tristate gate_and(std::vector<Pin *> deps)
	{
		auto input1 = deps[0];
		auto input2 = deps[1];
		std::cout << "And between " << input1->_component << ":" << input1->_index << " and " << input1->_component << ":" << input2->_index << std::endl;
		return (input1->_state == TRUE && input2->_state == TRUE ? TRUE : FALSE);
	}

	Tristate gate_nand(std::vector<Pin *> deps)
	{
		auto input1 = deps[0];
		auto input2 = deps[1];
		std::cout << "Nand between " << input1->_component << ":" << input1->_index << " and " << input1->_component << ":" << input2->_index << std::endl;
		return (input1->_state == TRUE && input2->_state == TRUE ? TRUE : FALSE);
	}

	Tristate gate_or(std::vector<Pin *> deps)
	{
		auto input1 = deps[0];
		auto input2 = deps[1];
		std::cout << "Or between " << input1->_component << ":" << input1->_index << " and " << input1->_component << ":" << input2->_index << std::endl;
		return (input1->_state == TRUE && input2->_state == TRUE ? TRUE : FALSE);
	}

	Tristate gate_nor(std::vector<Pin *> deps)
	{
		auto input1 = deps[0];
		auto input2 = deps[1];
		std::cout << "Nor between " << input1->_component << ":" << input1->_index << " and " << input1->_component << ":" << input2->_index << std::endl;
		return input1->_state == TRUE && input2->_state == TRUE ? TRUE : FALSE;
	}

	Tristate get_output(std::vector<Pin *> deps)
	{
		std::cout << deps[0]->_component << std::endl;
		auto input = deps[0];
		std::cout << "Get output from " << input->_component << ":" << input->_index << std::endl;
		return input->_state;
	}

	std::map<Gate, std::function<Tristate(std::vector<Pin *>)>> fct_gates =
	{
		{OR, gate_or},
		{NOR, gate_nor},
		{AND, gate_and},
		{NAND, gate_nand},
		{GET_OUTPUT, get_output}
	};
}
