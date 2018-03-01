//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// NanoTekSpice
//

#pragma once

namespace nts {
	class NanoTekSpice {
	public:
		NanoTekSpice();
		~NanoTekSpice();
		int startNano(const int, const char **);
	};
}