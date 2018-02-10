//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include "Output.hpp"

nts::Output::Output()
{
}

nts::Output::~Output()
{
}

void nts::Output::dump() const
{
	std::cout << _state << std::endl;
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
	return _state;
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	std::cout << "lol" << std::endl;
}