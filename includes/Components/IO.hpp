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
		Input();
		~Input();
		void dump() const;
		Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
	public:
		Tristate getState() { return _state; }
	private:
		Tristate _state;
	};
}
