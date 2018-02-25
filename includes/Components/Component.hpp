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

	class C4081 : public Component {
	public:
		C4081(std::string name) : Component(name, 6)
		{
			createPin();
		}

		void createPin()
		{
			_pins.push_back(new Pin(1, _name));
			_pins.push_back(new Pin(2, _name));
			_pins.push_back(new PinOutput(3, _name, {{_name, 1}, {_name, 2}}, AND));
			_pins.push_back(new PinOutput(4, _name, {{_name, 5}, {_name, 6}}, AND));
			_pins.push_back(new Pin(5, _name));
			_pins.push_back(new Pin(6, _name));
		}
	};

	Tristate get_output_from(std::string, std::size_t, std::map<std::string, Component *>compList);
}
