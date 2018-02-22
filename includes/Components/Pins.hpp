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
		Pins(std::size_t index, std::string component)
			: _component(component), _index(index) {}
		~Pins();
		std::string _component;
		std::size_t _index;
		std::vector<Pins> mdr;
	};
}
