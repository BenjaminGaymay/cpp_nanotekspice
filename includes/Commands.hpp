//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Commands
//

#pragma once

#include <iostream>
#include <map>
#include "Component.hpp"

namespace nts {
	class Commands {
	public:
		static int processCommands(const std::string &, std::map<std::string, nts::Component *> &);
		static int display(std::map<std::string, nts::Component *> &);
		static int simulate(std::map<std::string, nts::Component *> &);
		static int loop(std::map<std::string, nts::Component *> &);
		static int dump(std::map<std::string, nts::Component *> &);
		static int my_exit(std::map<std::string, nts::Component *> &);
		static int createSignal();
		static void quitLoop(int);
	};
}
