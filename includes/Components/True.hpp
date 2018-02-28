#pragma once

#include "Component.hpp"

namespace nts {
	class True : public Component {
	public:
		True(std::string name) : Component(name, "true", 1)
		{
			_pins.push_back(new PinOutput(1, _name, {}, GET_OUTPUT));
			_pins[0]->_state = TRUE;
		}
	};
}
