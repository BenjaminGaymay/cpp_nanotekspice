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
#include "IO.hpp"

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
	std::map<std::string, nts::Component *> componentList;

	componentList["and0"] = new nts::component4081("and0");
	componentList["out"] = new nts::Output("out");
	auto n1 = componentList["and0"];
	auto n2 = componentList["out"];

	// CONFIG DE BASE
	n1->_pins[0]->_state = nts::FALSE;
	n1->_pins[1]->_state = nts::TRUE;
	n1->_pins[5]->_state = nts::TRUE;

	// AND:5 RECUPERE AND:3
	delete n1->_pins[4];
	n1->_pins[4] = new nts::PinOutput(5, n1->_name, {{"and0", 3}, {"and0", 3}}, nts::GET_OUTPUT);

	// OUT RECUPERE AND:4
	delete n2->_pins[0];
	n2->_pins[0] = new nts::PinOutput(1, n2->_name, {{"and0", 4}, {"and0", 4}}, nts::GET_OUTPUT);

	// ON CHERCHER L'OUTPUT DU PIN 4
	n2->refreshPinById(1, componentList);

	// RESULTATS
	std::cout << "\nOUTPUT : " << (nts::get_output_from("out", 1, componentList) == nts::TRUE ? "True\n" : "False\n") << std::endl;

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
