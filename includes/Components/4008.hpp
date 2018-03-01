//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// 4008
//

#pragma once

#include "Component.hpp"

namespace nts {
	class C4008 : public Component {
	public:
		C4008(const std::string name) : Component(name, "4008",  15)
		{
			_pins.push_back(new Pin(1, _name));
			_pins.push_back(new Pin(2, _name));
			_pins.push_back(new Pin(3, _name));
			_pins.push_back(new Pin(4, _name));
			_pins.push_back(new Pin(5, _name));
			_pins.push_back(new Pin(6, _name));
			_pins.push_back(new Pin(7, _name));
			_pins.push_back(new PinUseless(8, _name));
			_pins.push_back(new Pin(9, _name));
			_pins.push_back(new PinOutput(10, _name, {{_name, 6}, {_name, 7}, {_name, 9}}, SUM));
			_pins.push_back(new PinOutput(11, _name, {{_name, 4}, {_name, 5}, {_name, 10}}, SUM));
			_pins.push_back(new PinOutput(12, _name, {{_name, 2}, {_name, 3}, {_name, 11}}, SUM));
			_pins.push_back(new PinOutput(13, _name, {{_name, 1}, {_name, 15}, {_name, 12}}, SUM));
			_pins.push_back(new PinUseless(14, _name));
			_pins.push_back(new Pin(15, _name));
		}
	};
}