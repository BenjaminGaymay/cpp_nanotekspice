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

nts::Component *nts::Factory::Get(nts::Comp::Comp comp, const std::string &name)
{
	switch (comp) {
		case Comp::INPUT:
			return new Input(name);
		case Comp::OUTPUT:
			return new Output(name);
		case Comp::C4001:
			return new C4001(name);
	}
	return nullptr;
}
