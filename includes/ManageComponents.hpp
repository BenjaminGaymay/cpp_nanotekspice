//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// manageComponents
//

#pragma once

#include "Component.hpp"

std::map<std::string, nts::Component *> createChipsets(std::vector<std::pair<std::string, std::string>> &);
void createLinks(std::vector<std::pair<std::string, std::string>> &, std::map<std::string, nts::Component *> &);
int changeInputValue(std::vector<std::string>, std::map<std::string, nts::Component *> &);
