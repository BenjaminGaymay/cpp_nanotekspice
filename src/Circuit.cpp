//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include "Circuit.hpp"

nts::Circuit::Circuit()
{
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::addComponent(nts::IComponent *cmp)
{
	_graph.push_back(cmp);
}

nts::Circuit nts::Circuit::operator<<(nts::IComponent *rhs)
{
	_graph.push_back(rhs);
	return *this;
}

void nts::Circuit::dump()
{
	for (auto const &el : _graph) {
		el->dump();
		// std::cout << "salut" << std::endl;
	}
}