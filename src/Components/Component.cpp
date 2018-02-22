//
// EPITECH PROJECT, 2018
// nano
// File description:
// nano
//
 
#include "Component.hpp"
 

nts::Component::Component(int id)
  : _id(id)
{}
 
nts::Component::~Component()
{}
 
nts::Component &nts::Component::operator>>(const nts::Component &rhs)
{
	_neighbors.push_back(rhs._id);
	return *this;
}

std::ostream &operator<<(std::ostream &os, const nts::Component &rhs)
{
	os << "Id : " << rhs._id << "\nConnected to : \n";
	for (int n : rhs._neighbors) {
		os << n << "\n";
	}
	return os;
}