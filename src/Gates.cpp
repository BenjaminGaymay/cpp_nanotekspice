//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Gates
//

#include "Component.hpp"

nts::Tristate gate_and(nts::Pin *input1, nts::Pin *input2)
{
	std::cout << "JE FAIS UN AND de " << input1->_component << ":" << input1->_index << " et " << input1->_component << ":" << input2->_index << std::endl;
	return (input1->_state == TRUE && input2->_state == TRUE ? TRUE : FALSE);
}

nts::Tristate gate_nand(nts::Pin *input1, nts::Pin *input2)
{
	std::cout << "JE FAIS UN NAND" << std::endl;
	return (input1->_state == input2->_state ? TRUE : FALSE);
}

nts::Tristate gate_or(nts::Pin *input1, nts::Pin *input2)
{
	std::cout << "JE FAIS UN OR" << std::endl;
	return (input1->_state == input2->_state ? TRUE : FALSE);
}

nts::Tristate gate_nor(nts::Pin *input1, nts::Pin *input2)
{
	std::cout << "JE FAIS UN NOR" << std::endl;
	return (input1->_state == input2->_state ? TRUE : FALSE);
}

nts::Tristate get_output(nts::Pin *input, nts::Pin *useless)
{
	std::cout << "GET OUTPUT" << std::endl;
	return (input->_state);
}
