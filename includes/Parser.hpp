//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Parser
//

#pragma once

#include <map>
#include "Component.hpp"
#include "ManageStrings.hpp"

std::map<std::string, nts::Component *> parseFile(std::string &);
