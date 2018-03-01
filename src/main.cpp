//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#include <exception>
#include <iostream>
#include "NanoTekSpice.hpp"

int main(const int ac, const char **av)
{
	nts::NanoTekSpice nano;

	if (ac < 2)
		return std::cerr << "Error: missing file name" << std::endl, 84;

	try {
		return nano.startNano(ac, av);
	} catch (const std::logic_error &e) {
		std::cerr << e.what() << std::endl;
		return 84;
	}
	return 0;
}
