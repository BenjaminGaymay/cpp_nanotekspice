//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Gates
//

#include <functional>
#include "Component.hpp"

namespace nts {
	Tristate gate_and(Pin *input1, Pin *input2)
	{
		std::cout << "And between " << input1->_component << ":" << input1->_index << " and " << input1->_component << ":" << input2->_index << std::endl;
		return (input1->_state == TRUE && input2->_state == TRUE ? TRUE : FALSE);
	}

	Tristate gate_nand(Pin *input1, Pin *input2)
	{
		std::cout << "JE FAIS UN NAND" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}

	Tristate gate_or(Pin *input1, Pin *input2)
	{
		std::cout << "JE FAIS UN OR" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}

	Tristate gate_nor(Pin *input1, Pin *input2)
	{
		std::cout << "JE FAIS UN NOR" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}

	Tristate get_output(Pin *input, Pin *useless)
	{
		useless = useless;
		std::cout << "Get output from " << input->_component << ":" << input->_index << std::endl;
		return (input->_state);
	}

	std::map<Gate, std::function<Tristate(Pin *, Pin *)>> fct_gates =
	{
		{OR, gate_or},
		{NOR, gate_nor},
		{AND, gate_and},
		{NAND, gate_nand},
		{GET_OUTPUT, get_output}
	};
}
