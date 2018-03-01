//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Gates
//

#pragma once

#include <map>
#include <functional>
#include "Component.hpp"

namespace nts {
	class Gates {
	public:
		static Tristate gate_and(std::vector<Pin *> &);
		static Tristate gate_nand(std::vector<Pin *> &);
		static Tristate gate_or(std::vector<Pin *> &);
		static Tristate gate_nor(std::vector<Pin *> &);
		static Tristate gate_xor(std::vector<Pin *> &);
		static Tristate gate_xnor(std::vector<Pin *> &);
		static Tristate gate_inverted(std::vector<Pin *> &);
		static Tristate gate_sum(std::vector<Pin *> &);
		static Tristate get_output(std::vector<Pin *> &);
		static std::map<Gate, std::function<Tristate(std::vector<Pin *> &)>> _fct_gates;
	};
}
