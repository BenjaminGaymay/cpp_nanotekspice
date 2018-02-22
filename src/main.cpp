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

nts::Tristate fct_and(std::vector<nts::Pin *> dependencies)
	{
		auto input1 = dependencies[0];
		auto input2 = dependencies[1];

		std::cout << "JE FAIS UN AND" << std::endl;
		return (input1->_state == input2->_state ? nts::TRUE : nts::FALSE);
	}

int main()//(int ac, char **av)
{

	auto n1 = new nts::And();
	auto n2 = new nts::And();

	n1->_pins[0]->_state = nts::TRUE;
	n1->_pins[1]->_state = nts::FALSE;
	n1->dump();
	n1->test();
	n1->dump();

	n2->_pins[0]->_state = n1->_pins[2]->_state;
	n2->_pins[1]->_state = nts::FALSE;
	std::cout << "\n2eme" << std::endl;
	n2->dump();
	n2->test();
	n2->dump();
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
