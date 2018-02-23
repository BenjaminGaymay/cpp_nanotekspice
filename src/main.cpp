//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include <iostream>
#include <fstream>
// #include "./src/Component.hpp"
// #include "Circuit.hpp"
// #include "Input.hpp"
// #include "Output.hpp"
#include "Component.hpp"

// void readFile(const std::string fileName, nts::Circuit &circuit)
// {
// 	std::ifstream file(fileName);
// 	std::string line;
// 	nts::Input *i = new nts::Input();
//
// 	if (file.is_open()) {
// 		while (!file.eof()) {
// 			std::getline(file, line);
// 			circuit << i;
// 		}
// 	}
// }

// void processCommands(std::string cmd)
// {
// 	if (cmd == "exit")
// 		exit(0);
// }


int main()//(int ac, char **av)
{
	std::map<std::string, nts::Component *> g_componentList;

	g_componentList["4081"] = new nts::component4081();
	auto n1 = g_componentList["4081"];

	// CONFIG DE BASE
	n1->_pins[0]->_state = nts::FALSE;
	n1->_pins[1]->_state = nts::TRUE;
	n1->_pins[5]->_state = nts::TRUE;

	// LE 5 RECUPERE L'OUTPUT DU 3
	delete n1->_pins[4];
	n1->_pins[4] = new nts::PinOutput(5, n1->_name, {{"4081", 3}, {"4081", 3}}, nts::GET_OUTPUT);

	// DUMP LA CONFIG
	n1->dump();

	// ON CHERCHER L'OUTPUT DU PIN 4
	n1->refreshPinById(4, g_componentList);

	// RESULTATS
	std::cout << "\nOUTPUT : " << (nts::get_output_from("4081", 4) == nts::TRUE ? "True\n" : "False\n") << std::endl;
	n1->dump();

	// std::string cmd;
	// nts::Circuit circuit;

	// if (ac == 1)
	// 	return 84;
	// readFile(av[1], circuit);
	// circuit.dump();
	// while (true) {
	// 	std::cout << "> ";
	// 	std::cin >> cmd;
	// 	if (std::cin.eof())
	// 		break;
	// 	processCommands(cmd);
	// }
	// return 0;
}
