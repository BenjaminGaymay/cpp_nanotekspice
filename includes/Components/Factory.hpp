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
#include "IComponent.hpp"
#include "IO.hpp"

namespace nts {
	class Factory {
	public:
		Factory();
		~Factory();

		std::map<const std::string, std::function<nts::IComponent*(const std::string &value)>> _factory;

		std::unique_ptr<nts::IComponent> createInput(const std::string &value) const;
		std::unique_ptr<nts::IComponent> createOutput(const std::string &value) const;
		// std::unique_ptr<nts::IComponent> createAnd(const std::string &value) const;
	};
}