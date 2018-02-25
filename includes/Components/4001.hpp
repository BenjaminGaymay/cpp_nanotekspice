//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// 4001
//

#pragma once

#include "Component.hpp"

namespace nts {
	class C4001 : public Component {
	public:
		C4001(const std::string name) : Component(name, 23)
		{
			_pins.push_back(new Pin(1, _name));
		}
	};
}