//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// 4069
//

#pragma once

#include "Component.hpp"

namespace nts {
	class C4069 : public Component {
	public:
		C4069(const std::string name) : Component(name, "4069",  14)
		{
			_pins.push_back(new Pin(1, _name));
			_pins.push_back(new PinOutput(2, _name, {{_name, 1}}, INVERTED));
			_pins.push_back(new Pin(3, _name));
			_pins.push_back(new PinOutput(4, _name, {{_name, 3}}, INVERTED));
			_pins.push_back(new Pin(5, _name));
			_pins.push_back(new PinOutput(6, _name, {{_name, 5}}, INVERTED));
			_pins.push_back(new PinUseless(7, _name));
			_pins.push_back(new PinOutput(8, _name, {{_name, 8}, {_name,9}}, INVERTED));
			_pins.push_back(new Pin(9, _name));
			_pins.push_back(new PinOutput(10, _name, {{_name, 11}}, INVERTED));
			_pins.push_back(new Pin(11, _name));
			_pins.push_back(new PinOutput(12, _name, {{_name, 13}}, INVERTED));
			_pins.push_back(new Pin(13, _name));
			_pins.push_back(new PinUseless(14, _name));
		}

		~C4069() {};
	};
}
