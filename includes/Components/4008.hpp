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
		C4008(const std::string name) : Component(name, "4008",  19)
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
			_pins.push_back(new PinOutput(3, _name, {{_name, 1}, {_name, 2}}, AND));
			_pins.push_back(new PinOutput(4, _name, {{_name, 5}, {_name, 6}}, AND));
			_pins.push_back(new Pin(5, _name));
			_pins.push_back(new Pin(6, _name));
			_pins.push_back(new PinUseless(7, _name));
			_pins.push_back(new Pin(8, _name));
			_pins.push_back(new Pin(9, _name));
			_pins.push_back(new PinOutput(10, _name, {{_name, 7}, {_name, 8}}, AND));
			_pins.push_back(new PinOutput(11, _name, {{_name, 12}, {_name, 13}}, AND));
			_pins.push_back(new Pin(12, _name));
			_pins.push_back(new Pin(13, _name));
			_pins.push_back(new PinUseless(14, _name));
		}
	};
}