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
	for (auto &value : _pins) {
		if (value->_type == OUTPUT) {
			auto tmp = static_cast<PinOutput *>(value);
			value->_state = gate_nand(tmp->_dependencies);
		}
	}
}

void nts::Component::dump() const 
{
	for (auto const &value : _pins) {
		std::cout << value->_component << " : " << value->_index << " : " << value->_state << std::endl;
	}
}