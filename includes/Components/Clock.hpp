//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Clock
//

#pragma once

#include "Component.hpp"

namespace nts {
	class Clock : public Component {
	public:
		Clock(std::string name) : Component(name, "clock", 1)
		{
			_pins.push_back(new PinOutput(1, _name, {}, GET_OUTPUT));
		}
	};
}
