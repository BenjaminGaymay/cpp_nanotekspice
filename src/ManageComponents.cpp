//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// manageComponents
//

#include "Factory.hpp"
#include "ManageStrings.hpp"

std::map<std::string, nts::Component *> createChipsets(std::vector<std::pair<std::string, std::string>> chipsets)
{
	std::map<std::string, nts::Component *> cList;
	nts::Factory f;

	for (auto &chipset : chipsets)
		cList[chipset.second] = f.Get(chipset.first, chipset.second);
	return cList;
}

void createLinks(std::vector<std::pair<std::string, std::string>> links, std::map<std::string, nts::Component *> cList)
{
	std::vector<std::string> first;
	std::vector<std::string> second;
	nts::Component *tmp;

	for (auto &link : links) {
		first = splitString(link.first, ':');
		second = splitString(link.second, ':');

		tmp = cList[second[0]];
		delete tmp->_pins[std::stoi(second[1]) - 1];
		tmp->_pins[std::stoi(second[1]) - 1] = new nts::PinOutput(std::stoi(second[1]), tmp->_name, {{first[0], std::stoi(first[1])}}, nts::GET_OUTPUT);
	}
}

int changeInputValue(std::vector<std::string> inputVector, std::map<std::string, nts::Component *> cList)
{
	nts::Component *input;

	if (inputVector.size() != 2)
		return std::cerr << "Error: Invalid argument: " << inputVector[0] << std::endl, 84;
	else if (cList.find(inputVector[0]) == cList.end())
		return std::cerr << "Error: " << inputVector[0] << " doesn't exist in components list" << std::endl, 84;
	else if (inputVector[1] != "0" and inputVector[1] != "1")
		return std::cerr << "Error: Bad value for " << inputVector[0] << '=' << inputVector[1] << std::endl, 84;

	input = cList[inputVector[0]];
	input->_pins[0]->_state = (inputVector[1] == "0" ? nts::FALSE : nts::TRUE);
	return 0;
}
