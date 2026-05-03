// Don't work on this file yet

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::toupper;

class Name {
public:
	const string& firstName, lastName, middleName;

	Name() :																		Name(nullptr, nullptr, nullptr, 0b000)			{}	//	Default name
	Name(const string& Name) :														Name(Name, nullptr, nullptr, 0b100)				{}	//	First Name given Only
	Name(const string& FirstName, const string& LastName) :							Name(FirstName, LastName, nullptr, 0b110)		{}	//	No Middle name is given
	Name(const string& FirstName, const string& LastName, const string& MiddleName):Name(FirstName, LastName, MiddleName, 0b111)	{}	//	All names are given.

	string nameString() {
		switch (constructorUsed) {
		case(0b100):
			return firstName;
		case(0b110):
			return firstName + ' ' + (char)toupper(middleName[0]) + ".";
		case(0b111):
			return firstName + ' ' + (char)toupper(middleName[0]) + ". " + lastName;
		default:
			return "John Doe";
		}
	}


private:
	// Private as no one should be able to choose what the constructor used type is.
	Name(const string& FirstName, const string& LastName, const string& MiddleName, uint8_t used) :
		firstName(FirstName),
		lastName(LastName),
		middleName(MiddleName),
		constructorUsed(used)
	{}

	// 0 = Default name.
	// 1 = First Name Only.
	// 2 = First & last name Only.
	// 3 = all values given.
	const uint8_t constructorUsed;	


	/// <summary>Modifies the input string in-place by converting its first character to uppercase.</summary>
	/// <param name="name">The string to format. If empty, no modification is performed.</param>
	void formatToName(string& name) {
		if (name.empty()) return;
		name[0] = static_cast<char>(toupper(static_cast<unsigned char>(name[0])));
	}
};