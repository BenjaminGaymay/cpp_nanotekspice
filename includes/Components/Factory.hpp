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
#include "4008.hpp"
#include "4011.hpp"
#include "4030.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"

namespace nts {
	class Factory {
	public:
		Factory();
		~Factory();
		static Component *createInput(const std::string &);
		static Component *createOutput(const std::string &);
		static Component *create4001(const std::string &);
		static Component *create4008(const std::string &);
		static Component *create4011(const std::string &);
		static Component *create4030(const std::string &);
		static Component *create4069(const std::string &);
		static Component *create4071(const std::string &);
		static Component *create4081(const std::string &);
		static Component *createTrue(const std::string &);
		static Component *createFalse(const std::string &);
		static Component *createClock(const std::string &);
		static std::map<const std::string, std::function<Component*(const std::string &)>> _fc_fac;
		Component *createComponent(const std::string &, const std::string &);
	};
}
