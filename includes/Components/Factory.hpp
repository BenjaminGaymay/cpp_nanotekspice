/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Factory
*/

#pragma once

#include <map>
#include <functional>
#include "IComponent.hpp"
#include "IO.hpp"

class Factory {
public:
	Factory();
	~Factory();

	std::map<const std::string, std::function<nts::IComponent*(const std::string &value)>> _factory;
};