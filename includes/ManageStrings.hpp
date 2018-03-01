//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// ManageStrings
//

#pragma once

#include <vector>

namespace nts {
	class ManageStrings {
	public:
		static std::string replaceStr(std::string, std::string, std::string &);
		static std::string lstrip(std::string &);
		static std::vector<std::string> splitString(std::string, char);
	};
}
