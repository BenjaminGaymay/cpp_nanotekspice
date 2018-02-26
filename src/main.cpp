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
	std::string cmd;
	if (ac < 2)
		return std::cerr << "Error: missing file name" << std::endl, 84;
	std::map<std::string, nts::Component *> cList;

	std::cout << "Initialization..\n" << std::endl;
	cList = parseFile(av[1]);

	for (auto i = 2 ; i < ac ; i++) {
		if (changeInputValue(splitString(av[i], '='), cList) == 84)
			return 84;
	}

	auto out = cList["out"];

	std::cout << "\nStarting simulation..\n" << std::endl;
	out->refreshPinById(1, cList);
	std::cout << "\nOUTPUT : " << (nts::get_output_from("out", 1, cList) == nts::TRUE ? "True" : "False") << std::endl;
	while (true) {
		std::cout << "> ";
		std::cin >> cmd;
		processCommands(cmd);
	}
	return 0;
}
