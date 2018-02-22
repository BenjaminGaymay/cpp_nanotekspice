/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Gates
*/

#include "Component.hpp"

namespace nts {
	Tristate gate_and(std::vector<Pin *> dependencies)
	{
		auto input1 = dependencies[0];
		auto input2 = dependencies[1];

		std::cout << "JE FAIS UN AND" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}

	Tristate gate_nand(std::vector<Pin *> dependencies)
	{
		auto input1 = dependencies[0];
		auto input2 = dependencies[1];

		std::cout << "JE FAIS UN AND" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}

	Tristate gate_or(std::vector<Pin *> dependencies)
	{
		auto input1 = dependencies[0];
		auto input2 = dependencies[1];

		std::cout << "JE FAIS UN AND" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}

	Tristate gate_nor(std::vector<Pin *> dependencies)
	{
		auto input1 = dependencies[0];
		auto input2 = dependencies[1];

		std::cout << "JE FAIS UN AND" << std::endl;
		return (input1->_state == input2->_state ? TRUE : FALSE);
	}
}