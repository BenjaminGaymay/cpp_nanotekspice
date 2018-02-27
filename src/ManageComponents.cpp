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
						std::string>> chipsets)
{
	std::map<std::string, nts::Component *> cList;
	nts::Factory f;

	if (chipsets.size() == 0)
		throw std::logic_error("Error: no chipset found");

	for (auto &chipset : chipsets) {
		cList[chipset.second] = f.Get(chipset.first, chipset.second);
		if (cList[chipset.second] == nullptr)
			throw std::logic_error("Error: chipset '" + chipset.first + "' doesn't exist");

	}
	return cList;
}

bool stringIsNumber(std::string str)
{
	for (auto &c : str) {
		if (! std::isdigit(c))
			return false;
	}
	return true;
}

void checkLinkError(std::vector<std::string> first, std::vector<std::string> second,
			std::map<std::string, nts::Component *> cList)
{
	if (cList.find(second[0]) == cList.end() or cList.find(first[0]) == cList.end())
		throw std::logic_error("Error: missing chipset to create link between '" + first[0] + "' and '" + second[0] + "'");
	else if (!(stringIsNumber(first[1])) or cList[first[0]]->_nb_pins < std::stoul(first[1]))
		throw std::logic_error("Error: pin '" + first[1] + "' doesn't exist for chipset '" + first[0] + "'");
	else if (!(stringIsNumber(second[1])) or cList[second[0]]->_nb_pins < std::stoul(second[1]))
		throw std::logic_error("Error: pin '" + second[1] + "' doesn't exist for chipset '" + second[0] + "'");
	else if (cList[first[0]]->_type == "input" and cList[second[0]]->_type == "input")
		throw std::logic_error("Error: link between inputs: '" + first[0] + "' and '" + second[0] + "'");
	else if (cList[first[0]]->_type == "output" and cList[second[0]]->_type == "output")
		throw std::logic_error("Error: link between outputs: '" + first[0] + "' and '" + second[0] + "'");
}

void createLinks(std::vector<std::pair<std::string, std::string>> links,
		std::map<std::string, nts::Component *> cList)
{
	std::vector<std::string> first;
	std::vector<std::string> second;
	nts::Component *tmp;

	if (links.size() == 0)
		throw std::logic_error("Error: no link found");

	for (auto &link : links) {
		first = splitString(link.first, ':');
		second = splitString(link.second, ':');

		checkLinkError(first, second, cList);

		tmp = cList[second[0]];
		delete tmp->_pins[std::stoi(second[1]) - 1];
		tmp->_pins[std::stoi(second[1]) - 1] = new nts::PinOutput(std::stoi(second[1]),
				tmp->_name, {{first[0], std::stoi(first[1])}}, nts::GET_OUTPUT);
	}
}

int changeInputValue(std::vector<std::string> inputVector, std::map<std::string, nts::Component *> cList)
{
	nts::Component *input;

	if (inputVector.size() != 2)
		return std::cerr << "Error: Invalid argument: " << inputVector[0] << std::endl, 84;
	else if (cList.find(inputVector[0]) == cList.end())
		return std::cerr << "Error: " << inputVector[0]
			<< " doesn't exist in components list" << std::endl, 84;
	else if (inputVector[1] != "0" and inputVector[1] != "1")
		return std::cerr << "Error: Bad value for " << inputVector[0] << std::endl, 84;

	input = cList[inputVector[0]];
	if (input->_type != "clock" and input->_type != "input")
		return std::cerr << "Error: Invalid argument: " << inputVector[0] << std::endl, 84;
	input->_pins[0]->_state = (inputVector[1] == "0" ? nts::FALSE : nts::TRUE);
	return 0;
}
