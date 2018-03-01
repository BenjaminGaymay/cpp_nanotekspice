//
// EPITECH PROJECT, 2018
// nano
// File description:
// nano
//

#include <iomanip>
#include "Component.hpp"
#include "Gates.hpp"

nts::Component::~Component()
{
	for (size_t i = 0; i < _pins.size(); i++)
		delete _pins[i];
}

std::vector<nts::Pin *> nts::Component::extractPins(std::map<std::string, Component *> &compList,
				std::vector<std::pair<std::string, std::size_t>> &dep)
{
	std::vector<Pin *> pins;

	for (auto &c: dep) {
		auto comp = compList[c.first];
		pins.push_back(comp->_pins[c.second - 1]);
	}
	return pins;
}

nts::Tristate nts::Component::compute(std::size_t id)
{
	// Gates g;
	if (_pins[id - 1]->_type != OUTPUT)
		return _pins[id - 1]->_state;

	auto actualPin = static_cast<PinOutput *>(_pins[id - 1]);
	auto dependencies = actualPin->_dependencies;

	if (dependencies.size() == 0)
		return actualPin->_state;

	auto listPins = extractPins(_cList, dependencies);


	for (auto &dep : dependencies)
		_cList[dep.first]->compute(dep.second);

	actualPin->_state = Gates::_fct_gates[actualPin->_gate](listPins);
	return actualPin->_state;
}

std::string nts::Component::getState(Tristate &value) const
{
	switch (value) {
		case nts::TRUE:
			return " is True";
		case nts::FALSE:
			return " is False";
		default:
			return " is Undefined";
	}
}

void nts::Component::dump() const
{
	std::string state;

	std::cout << "Name: " << _name << "\t\tType: " << _type << "\t\tNumber of Pins: " << _nb_pins << std::endl;
	for (auto &pin : _pins) {
		std::cout << "      -> pin " << std::setw(std::to_string(_pins.size()).length())
			<< std::left << pin->_index << getState(pin->_state) << std::endl;
	}
}
