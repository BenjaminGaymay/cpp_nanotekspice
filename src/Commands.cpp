//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Commands
//

#include <functional>
#include <map>
#include <signal.h>
#include <unistd.h>
#include "Component.hpp"
#include "ManageStrings.hpp"
#include "ManageComponents.hpp"

bool g_quitLoop = false;

int my_exit(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	(void)cList;
	exit(0);
}

int display(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	nts::Component *component;
	nts::Pin *pin;
	(void)cmd;

	for (auto &c : cList) {
		component = c.second;
		if (component->_type == "output") {
			pin = component->_pins[0];
			std::cout << component->_name << '=';
			if (pin->_state == nts::UNDEFINED)
				std::cout << "U" << std::endl;
			else
				std::cout << pin->_state << std::endl;
		}
	}
	return 0;
}

int simulate(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	nts::Component *component;
	(void)cmd;

	for (auto &c : cList) {
		component = c.second;
		if ((component->_type == "input" or component->_type == "clock")
			and component->_pins[0]->_state == nts::UNDEFINED)
			return std::cerr << "Error: " << component->_name << ":1 is undefined" << std::endl, 84;
	}

	for (auto &c : cList) {
		component = c.second;
		if (component->_type == "output")
			component->refreshPinById(1, cList);
		else if (component->_type == "clock")
			component->_pins[0]->_state = (component->_pins[0]->_state == nts::TRUE ? nts::FALSE : nts::TRUE);
	}
	return 0;
}

int loop(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	while (! g_quitLoop) {
		if (simulate(cmd, cList) == 84)
			return 84;
		usleep(500);
	}
	return 0;
}

int dump(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	for (auto &c : cList)
		c.second->dump();
	return 0;
}

void quitLoop(int empty)
{
	(void)empty;
	g_quitLoop = true;
}

int createSignal()
{
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = quitLoop;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
	g_quitLoop = false;
	return 0;
}

int processCommands(const std::string &command, std::map<std::string, nts::Component *> cList)
{
	std::map<const std::string, std::function<int(const std::string &, std::map<std::string, nts::Component *>)>> fc;

	fc["exit"] = my_exit;
	fc["simulate"] = simulate;
	fc["display"] = display;
	fc["loop"] = loop;
	fc["dump"] = dump;

	createSignal();
	if (fc.find(command) != fc.end()) {
		if (fc[command](command, cList) == 84)
			return 84;
	}
	else if (command.find('=') != std::string::npos) {
		if (changeInputValue(splitString(command, '='), cList) == 84)
			return 84;
	}
	return 0;
}
