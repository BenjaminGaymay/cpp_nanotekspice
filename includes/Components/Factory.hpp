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

namespace nts {
	class Factory {
	public:
		Factory();
		~Factory();

		std::map<const std::string, std::function<std::unique_ptr<IComponent>(const std::string &value)>> _factory;

		std::unique_ptr<IComponent> createInput(const std::string &value);
		std::unique_ptr<IComponent> createOutput(const std::string &value);
		// std::unique_ptr<IComponent> createAnd(const std::string &value) const;
	};
}