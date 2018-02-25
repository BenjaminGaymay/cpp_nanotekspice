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

nts::Component *nts::Factory::Get(std::string type, const std::string &name)
{
	nts::Comp::Comp comp = nts::Comp::types[type];

	switch (comp) {
		case Comp::INPUT:
			return new Input(name);
		case Comp::OUTPUT:
			return new Output(name);
		case Comp::C4001:
			return new C4001(name);
		case Comp::C4081:
			return new C4081(name);
	}
	return nullptr;
}
