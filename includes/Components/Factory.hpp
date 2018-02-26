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
#include "4011.hpp"
#include "4030.hpp"
#include "4069.hpp"
#include "4081.hpp"
#include "Clock.hpp"

namespace nts {
	namespace Comp {
		enum Comp {
			INPUT,
			OUTPUT,
			C4001,
			C4011,
			C4030,
			C4069,
			C4081,
			CLOCK
		};

		static std::map<std::string, Comp> types = {
			{"input", INPUT},
			{"output", OUTPUT},
			{"4001", C4001},
			{"4011", C4011},
			{"4030", C4030},
			{"4069", C4069},
			{"4081", C4081},
			{"clock", CLOCK}
		};
	}

	class Factory {
	public:
		Factory();
		~Factory();
		Component *Get(std::string, const std::string &);
	};
}
