//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include "Parser.hpp"
#include "ManageComponents.hpp"
#include "Commands.hpp"

int main(int ac, char **av)
{
	std::map<std::string, nts::Component *> cList;
	std::string cmd;

	if (ac < 2)
		return std::cerr << "Error: missing file name" << std::endl, 84;

	cList = parseFile(av[1]);

	for (auto i = 2 ; i < ac ; i++) {
		if (changeInputValue(splitString(av[i], '='), cList) == 84)
			return 84;
	}

	std::cout << "> ";
	while (std::cin >> cmd) {
		processCommands(cmd, cList);
		std::cout << "> ";
	}
	return 0;
}
