//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// parser
//

#include <fstream>
#include <exception>
#include "Parser.hpp"
#include "ManageComponents.hpp"

std::map<std::string, nts::Component *> nts::Parser::parseFile(std::string file)
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

	std::map<std::string, Component *> cList;

	while (std::getline(fd, line)) {
		ManageStrings::lstrip(line);
		if (line.find('#') != std::string::npos and line.find('#') != 0)
			line = ManageStrings::splitString(line, '#')[0];

		if (line.compare(0, 10, ".chipsets:") == 0)
			step = CHIPSETS;
		else if (line.compare(0, 7, ".links:") == 0)
			step = LINKS;
		else if (line[0] != '#' and line[0] != '\0') {
			pos = line.find(" ");
			if (pos != std::string::npos and step == CHIPSETS)
				chipsets.push_back({line.substr(0, pos), ManageStrings::lstrip(line.erase(0, pos))});
			else if (pos != std::string::npos and step == LINKS)
				links.push_back({line.substr(0, pos), ManageStrings::lstrip(line.erase(0, pos))});
			else
				throw std::logic_error("Error: invalid circuit");
			}
	}

	if (step == NONE)
		throw std::logic_error("Error: invalid circuit");

	cList = ManageComp::createChipsets(chipsets);
	ManageComp::createLinks(links, cList);

	for (auto &elem : chipsets)
		(cList[elem.second])->_cList = cList;

	return cList;
}
