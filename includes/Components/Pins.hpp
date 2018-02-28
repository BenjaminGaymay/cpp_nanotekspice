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
		SUM_CARRY,
		GET_OUTPUT
	};

	enum PinType {
		INPUT,
		OUTPUT
	};

	class Pin {
	public:
		Pin(std::size_t index, std::string component)
			: _component(component), _index(index), _state(UNDEFINED), _type(INPUT), _used(true) {}
		std::string _component;
		std::size_t _index;
		Tristate _state;
		PinType _type;
		bool _used;
	};

	class PinOutput : public Pin {
	public:
		PinOutput(std::size_t index, std::string component,
			std::vector<std::pair<std::string, std::size_t>> dep, Gate gate)
			: Pin(index, component), _dependencies(dep), _gate(gate)
		{
			_type = OUTPUT;
		}
		std::vector<std::pair<std::string, std::size_t>> _dependencies;
		Gate _gate;
	};

	class PinUseless : public Pin {
	public:
		PinUseless(std::size_t index, std::string component)
			: Pin(index, component)
		{
			_used = false;
		}
	};
}
