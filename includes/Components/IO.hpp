//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#pragma once

#include "Component.hpp"

namespace nts {
	class Input : public Component {
	public:
		Input() : Component("Input", 1)
		{
			_pins.push_back(new Pin(1, _name));
		}
	};

	class Output : public Component {
	public:
		Output() : Component("Output", 1)
		{
			_pins.push_back(new PinOutput(1, _name, {{_name, 0}, {_name, 0}}, GET_OUTPUT));
		}
	};
}
