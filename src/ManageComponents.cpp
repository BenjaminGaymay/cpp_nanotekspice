//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// manageComponents
//

#include <ctype.h>
#include <exception>
#include "Factory.hpp"
#include "ManageStrings.hpp"

std::map<std::string, nts::Component *> createChipsets(std::vector<std::pair<std::string,
						std::string>> &chipsets)
{
	std::map<std::string, nts::Component *> cList;
	nts::Factory f;

	if (chipsets.size() == 0)
		throw std::logic_error("Error: no chipset found");

	for (auto &chipset : chipsets) {
		cList[chipset.second] = f.createComponent(chipset.first, chipset.second);
		if (cList[chipset.second] == nullptr)
			throw std::logic_error("Error: chipset '" + chipset.first + "' doesn't exist");

	}
	return cList;
}

bool stringIsNumber(std::string &str)
{
	for (auto &c : str) {
		if (! std::isdigit(c))
			return false;
	}
	return true;
}

bool checkLinkError(std::vector<std::string> first, std::vector<std::string> &second,
			std::map<std::string, nts::Component *> &cList)
{
	if (cList.find(second[0]) == cList.end() or cList.find(first[0]) == cList.end())
		throw std::logic_error("Error: missing chipset to create link between '" + first[0] + "' and '" + second[0] + "'");
	else if (!(stringIsNumber(first[1])) or cList[first[0]]->_nb_pins < std::stoul(first[1]))
		throw std::logic_error("Error: pin '" + first[1] + "' doesn't exist for chipset '" + first[0] + "'");
	else if (!(stringIsNumber(second[1])) or cList[second[0]]->_nb_pins < std::stoul(second[1]))
		throw std::logic_error("Error: pin '" + second[1] + "' doesn't exist for chipset '" + second[0] + "'");

	auto firstPin = cList[first[0]]->_pins[std::stoul(first[1]) - 1];
	auto secondPin = cList[second[0]]->_pins[std::stoul(second[1]) - 1];

	if (firstPin->_type != nts::PinType::OUTPUT and secondPin->_type != nts::PinType::OUTPUT)
		throw std::logic_error("Error: missing output for link: '" + first[0] + ":" +  first[1] + "' and '" + second[0] + ":" +  second[1] + "'");
	else if (firstPin->_type == nts::PinType::OUTPUT and secondPin->_type == nts::PinType::OUTPUT)
		throw std::logic_error("Error: link between outputs: '" + first[0] + ":" + first[1] + "' and '" + second[0] + ":" +  second[1] + "'");

	return firstPin->_type == nts::PinType::OUTPUT;
}

void addLinkInComponent(std::vector<std::string> first, std::vector<std::string> &second,
			std::map<std::string, nts::Component *> &cList)
{
	nts::Component *tmp;

	tmp = cList[second[0]];
	delete tmp->_pins[std::stoi(second[1]) - 1];
	tmp->_pins[std::stoi(second[1]) - 1] = new nts::PinOutput(std::stoi(second[1]),
			tmp->_name, {{first[0], std::stoi(first[1])}}, nts::GET_OUTPUT);

	auto firstPin = cList[first[0]]->_pins[std::stoul(first[1]) - 1];
	auto secondPin = cList[second[0]]->_pins[std::stoul(second[1]) - 1];

	firstPin->_used = true;
	secondPin->_used = true;
}

void createLinks(std::vector<std::pair<std::string, std::string>> &links,
		std::map<std::string, nts::Component *> &cList)
{
	std::vector<std::string> first;
	std::vector<std::string> second;

	if (links.size() == 0)
		throw std::logic_error("Error: no link found");

	for (auto &link : links) {
		first = splitString(link.first, ':');
		second = splitString(link.second, ':');

		if (checkLinkError(first, second, cList))
			addLinkInComponent(first, second, cList);
		else
			addLinkInComponent(second, first, cList);
	}
}

int changeInputValue(std::vector<std::string> &inputVector, std::map<std::string, nts::Component *> &cList)
{
	nts::Component *input;

	if (inputVector.size() != 2)
		return std::cerr << "Error: Invalid argument: " << inputVector[0] << std::endl, 84;
	else if (cList.find(inputVector[0]) == cList.end())
		return std::cerr << "Error: '" << inputVector[0]
			<< "' doesn't exist in components list" << std::endl, 84;
	else if (inputVector[1] != "0" and inputVector[1] != "1")
		return std::cerr << "Error: Bad value for '" << inputVector[0] << "'" << std::endl, 84;

	input = cList[inputVector[0]];
	if (input->_type != "clock" and input->_type != "input")
		return std::cerr << "Error: Invalid argument: " << inputVector[0] << std::endl, 84;
	input->_pins[0]->_state = (inputVector[1] == "0" ? nts::FALSE : nts::TRUE);
	return 0;
}
