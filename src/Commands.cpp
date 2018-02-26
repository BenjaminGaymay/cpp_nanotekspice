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

void my_exit(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	(void)cList;
	exit(0);
}

void display(const std::string &cmd, std::map<std::string, nts::Component *> cList)
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
}

void simulate(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	nts::Component *component;
	(void)cmd;

	for (auto &c : cList) {
		component = c.second;
		if (component->_type == "output")
			component->refreshPinById(1, cList);
	}
}

void loop(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	while (! g_quitLoop) {
		simulate(cmd, cList);
		usleep(500);
	}
}

void dump(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	for (auto &c : cList)
		c.second->dump();
}

void quitLoop(int empty)
{
	(void)empty;
	g_quitLoop = true;
}

void createSignal()
{
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = quitLoop;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
	g_quitLoop = false;
}

void processCommands(const std::string &command, std::map<std::string, nts::Component *> cList)
{
	std::map<const std::string, std::function<void(const std::string &, std::map<std::string, nts::Component *>)>> fc;

	fc["exit"] = my_exit;
	fc["simulate"] = simulate;
	fc["display"] = display;
	fc["loop"] = loop;
	fc["dump"] = dump;

	createSignal();
	if (fc.find(command) != fc.end())
		fc[command](command, cList);
	else if (command.find('=') != std::string::npos)
		changeInputValue(splitString(command, '='), cList);

}
