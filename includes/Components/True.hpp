#pragma once

#include "Component.hpp"

namespace nts {
	class True : public Component {
	public:
		True(std::string name) : Component(name, "true", 1)
		{
			_pins.push_back(new Pin(1, _name));
			_pins[0]->_state = TRUE;
		}
	};
}