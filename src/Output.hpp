//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#pragma once

#include "IComponent.hpp"

namespace nts {
	class Output : public IComponent {
	public:
		Output();
		~Output();
		void dump() const;
		Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);

	public:
		Tristate getState() { return _state; }
	private:
		Tristate _state;
	};
}