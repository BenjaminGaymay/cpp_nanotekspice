/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Pins
*/

#pragma once

#include "IComponent.hpp"

namespace nts {

	enum Gate {
		OR,
		NOR,
		AND,
		NAND,
		XOR,
		XNOR,
		INVERTED,
		SUM,
		SUM_CARRY
	};

	class Pin {
	public:
		Pin(std::size_t index, std::string component)
			: _component(component), _index(index), _state(UNDEFINED) {}
		~Pin();
		std::string _component;
		std::size_t _index;
		Tristate _state;
		std::vector<Pin> _connected;
	};

	class PinOutput : public Pin {
	public:
		PinOutput(std::size_t index, std::string component, Gate gate)
			: Pin(index, component), _gate(gate) {}
		Gate _gate;
		std::vector<Pin> _dependencies;
	};
}
