//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// manageComponents
//

#pragma once

#include "Component.hpp"

namespace nts {
	class ManageComp {
	public:
		static std::map<std::string, nts::Component *> createChipsets(std::vector<std::pair<std::string, std::string>> &);
		static void createLinks(std::vector<std::pair<std::string, std::string>> &, std::map<std::string, nts::Component *> &);
		static int changeInputValue(std::vector<std::string>, std::map<std::string, nts::Component *> &);
		static bool stringIsNumber(std::string &);
		static bool checkLinkError(std::vector<std::string>, std::vector<std::string> &, std::map<std::string, 
			nts::Component *> &);
		static void addLinkInComponent(std::vector<std::string>, std::vector<std::string> &,
			std::map<std::string, nts::Component *> &);
	};
}
