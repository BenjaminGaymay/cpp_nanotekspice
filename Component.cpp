/*
** EPITECH PROJECT, 2018
** nano
** File description:
** nano
*/

#include "Component.hpp"

Component::Component(int id)
	: _id(id)
{}

Component::~Component()
{}

Component &Component::operator>>(const Component &rhs)
{
	_neighbors.push_back(rhs._id);
	return *this;
}