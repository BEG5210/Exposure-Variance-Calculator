#pragma once

#include "Name.h"
using std::string;


class Auther {
public:

	string username;
	Name name;

Auther(const Name nameClass, const string userName) :
		name(nameClass),
		username(userName)
	{}

};