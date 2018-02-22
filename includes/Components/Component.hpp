//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#pragma once

#include <iostream>
#include <vector>
#include "IComponent.hpp"
#include "Pins.hpp"

nts::Tristate fct_and(std::vector<nts::Pin *>);


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
		nts::Tristate compute(std::size_t pin = 1) { return TRUE; };
		void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {};
		void dump() const {
			for (auto const &value : _pins) {
				std::cout << value->_component << " : " << value->_index << " : " << value->_state << std::endl;
			}
		}
		void test()
		{
			for (auto &value : _pins) {
				if (value->_type == OUTPUT) {
					auto tmp = static_cast<PinOutput *>(value);
					value->_state = fct_and(tmp->_dependencies);
				}
			}
		}
	};

	class And : public Component {
	public:
		And() : Component("And", 3)
		{
			createPin();
		}

		void createPin()
		{
			_pins.push_back(new Pin(1, _name));
			_pins.push_back(new Pin(2, _name));
			_pins.push_back(new PinOutput(3, _name, {_pins[0], _pins[1]}, AND));
		}
	};

}
