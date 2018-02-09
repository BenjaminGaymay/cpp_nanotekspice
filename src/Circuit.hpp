//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// nanotekspice
//

#pragma once

#include <vector>
#include "IComponent.hpp"

namespace nts {
	class Circuit {
	public:
		Circuit();
		~Circuit();
		void addComponent(IComponent *cmp);
		Circuit operator<<(IComponent *rhs);
		std::vector<IComponent*> getGraph() {
			return _graph;
		};
		void dump();
	private:
		std::vector<IComponent*> _graph;
	};
}