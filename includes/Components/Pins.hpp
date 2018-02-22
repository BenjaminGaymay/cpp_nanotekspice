/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Pins
*/

#pragma once

#include "IComponent.hpp"

namespace nts {
	class Pin {
	public:
		Pin(std::size_t index, std::string component)
			: _component(component), _index(index) {}
		~Pin();
		std::string _component;
		std::size_t _index;
		nts::Tristate _state;
		std::vector<Pin> _connected;
	};

	class PinOutput {
	public:
		std::vector<Pin> _dependencies;
	};
}
