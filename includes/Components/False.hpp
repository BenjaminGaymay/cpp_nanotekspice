//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// False
//

#pragma once

#include "Component.hpp"

namespace nts {
	class False : public Component {
	public:
		False(std::string name) : Component(name, "false", 1)
		{
			_pins.push_back(new Pin(1, _name));
			_pins[0]->_state = FALSE;
		}
	};
}