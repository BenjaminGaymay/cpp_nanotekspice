/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Factory
*/

#pragma once

#include <map>
#include <functional>
#include <memory>
#include "Component.hpp"
#include "IO.hpp"
#include "4001.hpp"

namespace nts {
	namespace Comp {
		enum Comp {
			INPUT,
			OUTPUT,
			C4001,
			C4081
		};

		static std::map<std::string, Comp> types = {
			{"input", INPUT},
			{"output", OUTPUT},
			{"4001", C4001},
			{"4081", C4081}
		};
	}

	class Factory {
	public:
		Factory();
		~Factory();
		Component *Get(std::string, const std::string &);
	};
}
