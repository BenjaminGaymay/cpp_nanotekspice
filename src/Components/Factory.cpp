/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Factory
*/

#include "Factory.hpp"

nts::Factory::Factory()
{}

nts::Factory::~Factory()
{}

std::unique_ptr<nts::IComponent> nts::Factory::createInput(const std::string &value) const
{
	return std::make_unique<nts::Input>(value);
}

std::unique_ptr<nts::IComponent> nts::Factory::createOutput(const std::string &value) const
{
	return std::make_unique<nts::Output>(value);
}

// std::unique_ptr<nts::IComponent> nts::Factory::create4081(const std::string &value) const
// {
// 	return std::make_unique<C4081>(value);
// }