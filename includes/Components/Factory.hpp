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
			C4001
		};
	}

	class Factory {
	public:
		Factory();
		~Factory();
		Component *Get(Comp::Comp, const std::string &);
	};
}