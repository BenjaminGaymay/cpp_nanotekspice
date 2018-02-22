/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Gates
*/

#include "Component.hpp"

nts::Tristate gate_and(std::vector<nts::Pin *> dependencies)
{
	auto input1 = dependencies[0];
	auto input2 = dependencies[1];

	std::cout << "JE FAIS UN AND" << std::endl;
	return (input1->_state == input2->_state ? nts::TRUE : nts::FALSE);
}

nts::Tristate gate_nand(std::vector<nts::Pin *> dependencies)
{
	auto input1 = dependencies[0];
	auto input2 = dependencies[1];

	std::cout << "JE FAIS UN AND" << std::endl;
	return (input1->_state == input2->_state ? nts::TRUE : nts::FALSE);
}

nts::Tristate gate_or(std::vector<nts::Pin *> dependencies)
{
	auto input1 = dependencies[0];
	auto input2 = dependencies[1];

	std::cout << "JE FAIS UN AND" << std::endl;
	return (input1->_state == input2->_state ? nts::TRUE : nts::FALSE);
}

nts::Tristate gate_nor(std::vector<nts::Pin *> dependencies)
{
	auto input1 = dependencies[0];
	auto input2 = dependencies[1];

	std::cout << "JE FAIS UN AND" << std::endl;
	return (input1->_state == input2->_state ? nts::TRUE : nts::FALSE);
}