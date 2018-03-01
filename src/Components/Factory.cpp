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

nts::Component *nts::Factory::createComponent(const std::string &type, const std::string &name)
{
	if (nts::Comp::types.find(type) == nts::Comp::types.end())
		return nullptr;

	switch (nts::Comp::types[type]) {
		case Comp::INPUT:
			return new Input(name);
		case Comp::OUTPUT:
			return new Output(name);
		case Comp::C4001:
			return new C4001(name);
		case Comp::C4008:
			return new C4008(name);
		case Comp::C4011:
			return new C4011(name);
		case Comp::C4030:
			return new C4030(name);
		case Comp::C4069:
			return new C4069(name);
		case Comp::C4071:
			return new C4071(name);
		case Comp::C4081:
			return new C4081(name);
		case Comp::CTrue:
			return new True(name);
		case Comp::CFalse:
			return new False(name);
		case Comp::CLOCK:
			return new Clock(name);
	}
	return nullptr;
}
