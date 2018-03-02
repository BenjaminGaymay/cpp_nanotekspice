//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Commands
//

#include <functional>
#include <map>
#include <unistd.h>
#include <signal.h>
#include "ManageStrings.hpp"
#include "ManageComponents.hpp"
#include "Commands.hpp"

int nts::Commands::my_exit(std::map<std::string, nts::Component *> &cList)
{
	cList = cList;
	exit(0);
}

int nts::Commands::display(std::map<std::string, nts::Component *> &cList)
{
	nts::Component *component;
	nts::Pin *pin;

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

void nts::Commands::componentIsDefined(std::map<std::string, nts::Component *> &cList)
{
	nts::Component *component;

	for (auto &c : cList) {
		component = c.second;
		if ((component->_type == "input" or component->_type == "clock")
			and component->_pins[0]->_state == nts::UNDEFINED)
			throw std::logic_error("Error: '" + component->_name + "' is undefined");
	}
}

void nts::Commands::manageClocks(std::map<std::string, nts::Component *> &cList)
{
	nts::Component *component;

	for (auto &c : cList) {
		component = c.second;
		if (component->_type == "clock")
			component->_pins[0]->_state = (component->_pins[0]->_state == nts::TRUE ? nts::FALSE : nts::TRUE);
	}
}


int nts::Commands::simulate(std::map<std::string, nts::Component *> &cList)
{
	nts::Component *component;

	componentIsDefined(cList);
	for (auto &c : cList) {
		component = c.second;
		if (component->_type == "output") {
			auto tmpPin = static_cast<nts::Pin *>(component->_pins[0]);

			if (! tmpPin->_used)
				throw std::logic_error("Error: output '" + component->_name + "' isn't linked to anything");

			component->compute(1);
		}
	}

	manageClocks(cList);

	nts::Pin::_loopNbr += 1;
	return 0;
}


int nts::Commands::dump(std::map<std::string, nts::Component *> &cList)
{
	std::size_t i = 0;

	for (auto &c : cList) {
		if (i != 0)
			std::cout << std::endl;
		c.second->dump();
		i++;
	}
	return 0;
}

static bool g_quitLoop = false;

int nts::Commands::createSignal()
{
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = &quitLoop;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
	g_quitLoop = false;
	return 0;
}

void nts::Commands::quitLoop(int empty)
{
	(void)empty;
	g_quitLoop = true;
}

int nts::Commands::loop(std::map<std::string, nts::Component *> &cList)
{
	while (! g_quitLoop) {
		if (nts::Commands::simulate(cList) == 84)
			return 84;
		usleep(500);
	}
	return 0;
}

int nts::Commands::processCommands(const std::string &command, std::map<std::string, nts::Component *> &cList)
{
	std::map<const std::string, std::function<int(std::map<std::string, nts::Component *> &)>> fc;

	fc["exit"] = my_exit;
	fc["simulate"] = simulate;
	fc["display"] = display;
	fc["loop"] = loop;
	fc["dump"] = dump;

	createSignal();
	if (fc.find(command) != fc.end()) {
		if (fc[command](cList) == 84)
			return 84;
	}
	else if (command.find('=') != std::string::npos) {
		if (ManageComp::changeInputValue(ManageStrings::splitString(command, '='), cList) == 84)
			return 84;
	}
	else
		std::cerr << "Error: '" << command << "' command not found" << std::endl;
	return 0;
}
