//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NanoTekSpice
//

#include "ManageComponents.hpp"
#include "ManageStrings.hpp"
#include "Commands.hpp"
#include "Parser.hpp"
#include "NanoTekSpice.hpp"

nts::NanoTekSpice::NanoTekSpice()
{}

nts::NanoTekSpice::~NanoTekSpice()
{}

int nts::NanoTekSpice::startNano(const int ac, const char **av)
{
	std::map<std::string, nts::Component *> cList;
	std::string cmd;

	cList = nts::Parser::parseFile(av[1]);
	for (auto i = 2 ; i < ac ; i++) {
		if (nts::ManageComp::changeInputValue(nts::ManageStrings::splitString(av[i], '='), cList) == 84)
			return 84;
	}

	nts::Commands::simulate(cList);
	nts::Commands::display(cList);

	std::cout << "> ";
	while (std::cin >> cmd) {
		nts::Commands::processCommands(cmd, cList);
		std::cout << "> ";
	}
	return 0;
}