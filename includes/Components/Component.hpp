//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "IComponent.hpp"
#include "Pins.hpp"

namespace nts {
	class Component : public IComponent{
	public:
		Component(std::string name, std::string type, std::size_t nb_pins)
			: _name(name), _type(type), _nb_pins(nb_pins) {}
		~Component();
		std::string _name;
		std::string _type;
		std::vector<Pin *> _pins;
		std::size_t _nb_pins;
		std::map<std::string, Component *> _cList;

		// Useless ?
		nts::Tristate compute(std::size_t pin = 1);
		void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {pin = pin; other = other; otherPin = otherPin;};
		void dump() const;
		std::vector<Pin *> extractPins(std::map<std::string, Component *>compList, std::vector<std::pair<std::string, std::size_t>>);
	};
}
