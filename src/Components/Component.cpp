//
// EPITECH PROJECT, 2018
// nano
// File description:
// nano
//

#include "Component.hpp"
#include "Gates.hpp"

nts::Component::~Component()
{
	for (size_t i = 0; i < _pins.size(); i++)
		delete _pins[i];
}

std::vector<nts::Pin *> nts::Component::extractPins(std::map<std::string, Component *> compList, std::vector<std::pair<std::string, std::size_t>> dep)
{
	std::vector<Pin *> pins;

	for (auto &c: dep) {
		auto comp = compList[c.first];
		pins.push_back(comp->_pins[c.second - 1]);
	}
	return pins;
}

void nts::Component::refreshPinById(std::size_t id, std::map<std::string, Component *> compList)
{
	if (_pins[id - 1]->_type != OUTPUT)
		return ;

	auto actualPin = static_cast<PinOutput *>(_pins[id - 1]);
	auto dependencies = actualPin->_dependencies;
	auto listPins = extractPins(compList, dependencies);

	for (auto &dep : dependencies)
		compList[dep.first]->refreshPinById(dep.second, compList);
	actualPin->_state = fct_gates[actualPin->_gate](listPins);
}

void nts::Component::dump() const
{
	for (auto const &value : _pins) {
		std::cout << value->_component << " : " << value->_index << " : " << value->_state << std::endl;
	}
}
