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

void nts::Component::refreshPinById(std::size_t id, std::map<std::string, Component *>compList)
{
	if (_pins[id - 1]->_type != OUTPUT)
		return ;

	auto actualPin = static_cast<PinOutput *>(_pins[id - 1]);
	auto dependencies = actualPin->_dependencies;

	auto dep0 = compList[dependencies[0].first];
	auto dep1 = compList[dependencies[1].first];
	auto pin0 = dep0->_pins[dependencies[0].second - 1];
	auto pin1 = dep1->_pins[dependencies[1].second - 1];


	std::cout << "Pin " << id << " from " << actualPin->_component << " component request " << dependencies[1].first << ":" << dependencies[0].second << " and " << dependencies[1].first << ":" << dependencies[1].second  << std::endl;

	dep0->refreshPinById(dependencies[0].second, compList);
	dep1->refreshPinById(dependencies[1].second, compList);
	actualPin->_state = fct_gates[actualPin->_gate](pin0, pin1);
}

void nts::Component::dump() const
{
	for (auto const &value : _pins) {
		std::cout << value->_component << " : " << value->_index << " : " << value->_state << std::endl;
	}
}

nts::Tristate nts::get_output_from(std::string name, std::size_t pinID)
{
	//auto component = nts::g_componentList["4081"];
	//auto pin = component->_pins[pinID - 1];


	//std::cout << "GET OUTPUT from " << component->_name << std::endl;
	//return (pin->_state);
}
