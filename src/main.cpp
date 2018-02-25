//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include <iostream>
#include <fstream>
#include "Component.hpp"
#include "IO.hpp"
#include "Factory.hpp"
#include "Commands.hpp"

std::string replaceStr(std::string oldStr, std::string newStr, std::string &str)
{
	size_t index = 0;
	size_t oldStrLen = oldStr.length();

	while (true) {
		index = str.find(oldStr, 0);
		if (index == std::string::npos)
			break;
		str.replace(index, oldStrLen, newStr);
		index += oldStrLen;
	}
	return str;
}

std::string lstrip(std::string &str)
{
	std::string::iterator it = str.begin();

	replaceStr("\t", " ", str);
	for (auto &c : str) {
		if (c == ' ')
			it += 1;
		else
			break;
	}
	str.erase(str.begin(), it);
	return str;
}

std::map<std::string, nts::Component *> createChipsets(std::vector<std::pair<std::string, std::string>> chipsets)
{
	std::map<std::string, nts::Component *> cList;
	nts::Factory f;

	for (auto &chipset : chipsets) {
		std::cout << "Chipset name " << chipset.second << " (" << chipset.first << ")"<< std::endl;
		cList[chipset.second] = f.Get(chipset.first, chipset.second);
	}
	return cList;
}

std::vector<std::string> splitString(std::string str, char separator)
{
	std::string tmp = "";
	std::vector<std::string> splited;

	for (auto c: str) {
		if (c != separator)
			tmp += c;
		else if (c == separator && tmp != "") {
			splited.push_back(tmp);
			tmp = "";
		}
	}
	if (tmp != "")
		splited.push_back(tmp);
	return splited;
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
		tmp->_pins[std::stoi(second[1]) - 1] = new nts::PinOutput(std::stoi(first[1]), tmp->_name, {{first[0], std::stoi(first[1])},  {first[0], std::stoi(first[1])}}, nts::GET_OUTPUT);

		std::cout << "Connect " << link.first << " to " << link.second << std::endl;
	}
}

std::map<std::string, nts::Component *> parseFile(std::string file)
{
	std::ifstream fd(file);
	std::string line;
	enum parsingStep {
		NONE,
		CHIPSETS,
		LINKS
	};
	parsingStep step = NONE;
	std::vector<std::pair<std::string, std::string>> chipsets;
	std::vector<std::pair<std::string, std::string>> links;
	std::size_t pos;

	std::map<std::string, nts::Component *> cList;

	while (std::getline(fd, line)) {
		lstrip(line);
		if (line.compare(0, 10, ".chipsets:") == 0)
			step = CHIPSETS;
		else if (line.compare(0, 7, ".links:") == 0)
			step = LINKS;
		else if (line[0] != '#' and line[0] != '\0') {
			pos = line.find(" ");
			if (pos != std::string::npos and step == CHIPSETS)
				chipsets.push_back({line.substr(0, pos), lstrip(line.erase(0, pos))});
			else if (pos != std::string::npos and step == LINKS)
				links.push_back({line.substr(0, pos), lstrip(line.erase(0, pos))});
			}
	}

	cList = createChipsets(chipsets);
	createLinks(links, cList);
	return cList;
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;

	std::map<std::string, nts::Component *> cList;

	std::cout << "Initialization..\n" << std::endl;
	cList = parseFile("files/file1");
	auto i0 = cList["i0"];
	auto i1 = cList["i1"];
	auto i2 = cList["i2"];

	i0->_pins[0]->_state = nts::TRUE;
	i1->_pins[0]->_state = nts::TRUE;
	i2->_pins[0]->_state = nts::TRUE;

	auto out = cList["out"];

	std::cout << "\nStarting simulation..\n" << std::endl;
	out->refreshPinById(1, cList);
	std::cout << "\nOUTPUT : " << (nts::get_output_from("out", 1, cList) == nts::TRUE ? "True" : "False") << std::endl;

	return 0;
}
