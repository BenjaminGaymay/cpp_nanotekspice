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

void processCommands(const std::string &, std::map<std::string, nts::Component *>);
int display(const std::string &cmd, std::map<std::string, nts::Component *>);
