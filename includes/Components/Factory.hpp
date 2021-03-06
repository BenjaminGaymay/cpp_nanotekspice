/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Factory
*/

#pragma once

#include <map>
#include <functional>
#include <memory>
#include "Component.hpp"
#include "IO.hpp"
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4030.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"

namespace nts {
	class Factory {
	public:
		using FACTORY_FUNCTION = std::unique_ptr<IComponent>(Factory::*)(const std::string &name) const noexcept;
		std::map<const std::string, FACTORY_FUNCTION> _fc_fac;
		Factory()
		{
			_fc_fac["input"] = &Factory::createInput;
			_fc_fac["output"] = &Factory::createOutput;
			_fc_fac["4001"] = &Factory::create4001;
			_fc_fac["4008"] = &Factory::create4008;
			_fc_fac["4011"] = &Factory::create4011;
			_fc_fac["4030"] = &Factory::create4030;
			_fc_fac["4069"] = &Factory::create4069;
			_fc_fac["4071"] = &Factory::create4071;
			_fc_fac["4081"] = &Factory::create4081;
			_fc_fac["clock"] = &Factory::createClock;
			_fc_fac["true"] = &Factory::createTrue;
			_fc_fac["false"] = &Factory::createFalse;	
		};
		~Factory() {};
		std::unique_ptr<IComponent> createInput(const std::string &name) const noexcept
		{
			return std::make_unique<Input>(name);
		}

		std::unique_ptr<IComponent> createOutput(const std::string &name) const noexcept
		{
			return std::make_unique<Output>(name);
		}

		std::unique_ptr<IComponent> create4001(const std::string &name) const noexcept
		{
			return std::make_unique<C4001>(name);
		}

		std::unique_ptr<IComponent> create4008(const std::string &name) const noexcept
		{
			return std::make_unique<C4008>(name);
		}

		std::unique_ptr<IComponent> create4011(const std::string &name) const noexcept
		{
			return std::make_unique<C4011>(name);
		}

		std::unique_ptr<IComponent> create4030(const std::string &name) const noexcept
		{
			return std::make_unique<C4030>(name);
		}

		std::unique_ptr<IComponent> create4069(const std::string &name) const noexcept
		{
			return std::make_unique<C4069>(name);
		}

		std::unique_ptr<IComponent> create4071(const std::string &name) const noexcept
		{
			return std::make_unique<C4071>(name);
		}

		std::unique_ptr<IComponent> create4081(const std::string &name) const noexcept
		{
			return std::make_unique<C4081>(name);
		}

		std::unique_ptr<IComponent> createTrue(const std::string &name) const noexcept
		{
			return std::make_unique<True>(name);
		}

		std::unique_ptr<IComponent> createFalse(const std::string &name) const noexcept
		{
			return std::make_unique<False>(name);
		}

		std::unique_ptr<IComponent> createClock(const std::string &name) const noexcept
		{
			return std::make_unique<Clock>(name);
		}

		std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &name)
		{
			if (_fc_fac.find(type) == _fc_fac.end())
				return nullptr;
			return (this->*_fc_fac[type])(name);
		}
	};
}
