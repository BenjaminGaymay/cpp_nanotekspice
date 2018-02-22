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

namespace nts {
	class Component : public IComponent{
	public:
		~Component();
		std::string _name;
		std::vector<nts::Pins*> _pins;
		std::size_t _nb_pins;
	};
}
 
std::ostream &operator<<(std::ostream &, const nts::Component &);