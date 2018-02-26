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
		Component(std::string name, std::size_t nb_pins)
			: _name(name), _nb_pins(nb_pins) {}
		~Component();
		std::string _name;
		std::vector<Pin *> _pins;
		std::size_t _nb_pins;

		// Useless ?
		nts::Tristate compute(std::size_t pin = 1) { pin = pin; return TRUE; };
		void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {pin = pin; other = other; otherPin = otherPin;};
		void dump() const;
		void refreshPinById(std::size_t, std::map<std::string, Component *>);
		std::vector<Pin *> extractPins(std::map<std::string, Component *>compList, std::vector<std::pair<std::string, std::size_t>>);
	};

	class And : public Component {
	public:
		And(std::string name) : Component(name, 3)
		{
			createPin();
		}

		void createPin()
		{
			_pins.push_back(new Pin(1, _name));
			_pins.push_back(new Pin(2, _name));
			_pins.push_back(new PinOutput(3, _name, {{_name, 1}, {_name, 2}}, AND));
		}
	};

	Tristate get_output_from(std::string, std::size_t, std::map<std::string, Component *>compList);
}
