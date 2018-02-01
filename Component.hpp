/*
** EPITECH PROJECT, 2018
** nano
** File description:
** nano
*/

#pragma once

#include <iostream>
#include <fstream>
#include <list>

class Component {
public:
	Component(int);
	~Component();
	std::list<int> _neighbors;
	int _id;
	Component &operator>>(const Component &);
protected:
private:
};

std::ostream &operator<<(std::ostream &os, Component &rhs)
{
	os << "Id : " << rhs._id << std::endl;
	for (int n : rhs._neighbors) {
		os << n << std::endl;
	}
	return os;
}