//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include <exception>
#include "Parser.hpp"
#include "ManageComponents.hpp"
#include "Commands.hpp"

int startNano(const int ac, const char **av)
{
	std::map<std::string, nts::Component *> cList;
	std::string cmd;

	cList = parseFile(av[1]);
	for (auto i = 2 ; i < ac ; i++) {
		if (changeInputValue(splitString(av[i], '='), cList) == 84)
			return 84;
	}

	simulate("", cList);
	display("", cList);

	std::cout << "> ";
	while (std::cin >> cmd) {
		processCommands(cmd, cList);
		std::cout << "> ";
	}
	return 0;
}

int main(const int ac, const char **av)
{
	if (ac < 2)
		return std::cerr << "Error: missing file name" << std::endl, 84;

	try {
		return startNano(ac, av);
	} catch (const std::logic_error &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}
