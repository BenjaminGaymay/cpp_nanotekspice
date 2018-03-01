/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Factory
*/

#include "Factory.hpp"

namespace nts {
	Factory::Factory()
	{}

	Factory::~Factory()
	{}

	Component *Factory::createInput(const std::string &name)
	{
		return new Input(name);
	}

	Component *Factory::createOutput(const std::string &name)
	{
		return new Output(name);
	}

	Component *Factory::create4001(const std::string &name)
	{
		return new C4001(name);
	}

	Component *Factory::create4008(const std::string &name)
	{
		return new C4008(name);
	}

	Component *Factory::create4011(const std::string &name)
	{
		return new C4011(name);
	}

	Component *Factory::create4030(const std::string &name)
	{
		return new C4030(name);
	}

	Component *Factory::create4069(const std::string &name)
	{
		return new C4069(name);
	}

	Component *Factory::create4071(const std::string &name)
	{
		return new C4071(name);
	}

	Component *Factory::create4081(const std::string &name)
	{
		return new C4081(name);
	}

	Component *Factory::createTrue(const std::string &name)
	{
		return new True(name);
	}

	Component *Factory::createFalse(const std::string &name)
	{
		return new False(name);
	}

	Component *Factory::createClock(const std::string &name)
	{
		return new Clock(name);
	}

	Component *Factory::createComponent(const std::string &type, const std::string &name)
	{
		if (_fc_fac.find(type) == _fc_fac.end())
			return nullptr;
		return _fc_fac[type](name);
	}

	std::map<const std::string, std::function<nts::Component*(const std::string &)>> Factory::_fc_fac =
	{
		{"input", &createInput},
		{"output", &createOutput},
		{"4001", &create4001},
		{"4008", &create4008},
		{"4011", &create4011},
		{"4030", &create4030},
		{"4069", &create4069},
		{"4071", &create4071},
		{"4081", &create4081},
		{"true", &createTrue},
		{"false", &createFalse},
		{"clock", &createClock}
	};
}