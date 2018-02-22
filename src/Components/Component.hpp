//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#pragma once
 
#include <iostream>
#include <list>
#include "IComponent.hpp"

namespace nts {
	class Component : public IComponent{
	public:
		Component(int);
		~Component();
		std::list<int> _neighbors;
		int _id;
		Component &operator>>(const Component &);
	protected:
	private:
	};
}
 
std::ostream &operator<<(std::ostream &, const nts::Component &);