//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// manageComponents
//

#pragma once

#include "Component.hpp"

std::map<std::string, nts::Component *> createChipsets(std::vector<std::pair<std::string, std::string>> &);
void createLinks(std::vector<std::pair<std::string, std::string>> links &, std::map<std::string, nts::Component *> &);
int changeInputValue(std::vector<std::string> inputVector &, std::map<std::string, nts::Component *> &);
