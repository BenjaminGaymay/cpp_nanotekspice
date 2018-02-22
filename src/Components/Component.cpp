//
// EPITECH PROJECT, 2018
// nano
// File description:
// nano
//

#include "Component.hpp"
#include "Gates.hpp"

nts::Component::~Component()
{}

void nts::Component::refreshOutput()
{
	// for (auto &value : _pins) {
	// 	if (value->_type == OUTPUT) {
	// 		auto tmp = static_cast<PinOutput *>(value);
	// 		value->_state = fct_gates[tmp->_gate](tmp->_dependencies);
	// 	}
}

void nts::Component::refreshPinById(std::size_t id)
{
	if (_pins[id - 1]->_type != OUTPUT)
		return ;

	auto actualPin = static_cast<PinOutput *>(_pins[id - 1]);
	auto dep0 = _pins[actualPin->_dependencies[0] - 1];
	auto dep1 = _pins[actualPin->_dependencies[1] - 1];

	std::cout << "Refreshing " << _name << " starting by pin " << id << std::endl;
	if (dep0->_state == nts::UNDEFINED) {
		std::cout << dep0->_component << " : " << dep0->_index << " UNDEFINED" << std::endl;
		refreshPinById(dep0->_index);
	}
	if (dep1->_state == nts::UNDEFINED) {
		std::cout << dep1->_component << " : " << dep1->_index << " UNDEFINED" << std::endl;
		refreshPinById(dep1->_index);
	}
	actualPin->_state = fct_gates[actualPin->_gate](dep0, dep1);
}

void nts::Component::dump() const
{
	for (auto const &value : _pins) {
		std::cout << value->_component << " : " << value->_index << " : " << value->_state << std::endl;
	}
}
