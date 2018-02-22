/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Pins
*/

#pragma once

namespace nts {
	class Pins {
	public:
		Pins();
		~Pins();
		std::string _component;
		std::size_t _index;
	};
}
