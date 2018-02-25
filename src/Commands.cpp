//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Commands
//

#include <iostream>
#include <map>
#include <functional>

void quit(const std::string &cmd)
{
	exit(0);
}

void display(const std::string &cmd)
{
	(void)cmd;
}

void simulate(const std::string &cmd)
{
	(void)cmd;
}

void loop(const std::string &cmd)
{
	std::cout << "salut" << std::endl;
	(void)cmd;
}

void processCommands(const std::string &command)
{
	std::map<const std::string, std::function<void(const std::string &)>> fc;

	fc["quit"] = quit;
	fc["simulate"] = simulate;
	fc["display"] = display;
	fc["loop"] = loop;

	if (fc.find(command) != fc.end())
		fc[command](command);
}