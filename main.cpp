//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include <iostream>
#include <fstream>
// #include "./src/Component.hpp" 
#include "Circuit.hpp"
#include "Input.hpp"
#include "Output.hpp"

void readFile(const std::string fileName, nts::Circuit &circuit)
{
	std::ifstream file(fileName);
	std::string line;
	nts::Input *i = new nts::Input();

	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, line);
			circuit << i;
		}
	}
}

void processCommands(std::string cmd)
{
	if (cmd == "exit")
		exit(0);
}

int main(int ac, char **av)
{
	std::string cmd;
	nts::Circuit circuit;
	
	if (ac == 1)
		return 84;
	readFile(av[1], circuit);
	circuit.dump();
	while (true) {
		std::cout << "> ";
		std::cin >> cmd;
		if (std::cin.eof())
			break;
		processCommands(cmd);
	}
	return 0;
}