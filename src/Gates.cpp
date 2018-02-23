/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Gates
*/

#include "Component.hpp"

namespace nts {
	Tristate gate_and(Pin *input1, Pin *input2)
	{
		std::cout << "JE FAIS UN AND de " << input1->_component << ":" << input1->_index << " et " << input1->_component << ":" << input2->_index << std::endl;
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
		std::cout << "GET OUTPUT" << std::endl;
		return (input->_state);
	}
}
