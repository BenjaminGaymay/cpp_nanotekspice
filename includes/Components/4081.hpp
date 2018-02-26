//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// 4081
//

#pragma once

#include "Component.hpp"

namespace nts {
	class C4081 : public Component {
	public:
		C4081(std::string name) : Component(name, "4081", 6)
		{
			_pins.push_back(new Pin(1, _name));
			_pins.push_back(new Pin(2, _name));
			_pins.push_back(new PinOutput(3, _name, {{_name, 1}, {_name, 2}}, AND));
			_pins.push_back(new PinOutput(4, _name, {{_name, 5}, {_name, 6}}, AND));
			_pins.push_back(new Pin(5, _name));
			_pins.push_back(new Pin(6, _name));
		}

		~C4081() {};
	};
}
