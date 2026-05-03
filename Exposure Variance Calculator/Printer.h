
#pragma once

#include <iostream>
using std::cout;
using std::endl;

void printCopyright(/*const bool verbose*/) {
	cout	<< "Copyright Information:" << endl
			<< "	Author:	Thomas Federico" << endl
			<< "	Last Update:	29 - 4 - 2026" << endl
			<< endl
			<< "	This software, its code, and its future and previous versions are under a GNU Affero General Public V3.0 License" << endl
			<< endl;
}

void printRepoInf(/*const bool verbose*/) {
	cout	<< "find out more about this program and its project here: https://github.com/BEG5210/Exposure-Variance-Calculator.git" << endl
			<< endl;
}

void printTutorial(/*const bool verbose*/) {
	cout	<< "If you have an image that is perfectly exposed and want to know the EV of the scene, this tool can be useful." << std::endl
			<< endl;
}

void printValues(const float shutterSpeed, const float apeature, const int iso) {
	cout	<< "Inputted Values:" << endl
			<< "	shutterSpeed:	" << "1/" << shutterSpeed << "	[" << 1 / shutterSpeed << "]" << endl
			<< "	aperture:	f/" << apeature << "	[" << apeature << "]" << endl
			<< "	iso:		" << iso << "	[" << iso << "]" << endl
			<< endl;
}

void printEquation(const float shutterSpeed, const float apeature, const int iso) {
	cout	<< "Equation [with values subbed in]:	log2[( " << apeature << "^2 * 100 ) / ( " << 1 / shutterSpeed << " * " << iso << " )]" << endl
			<< endl;
}

void printEquation() {
	cout	<< "Equation:	log2[( apeature^2 * 100 ) / ( 1 / shutterSpeed * iso )]" << endl
			<< endl;
}

//Reccomended you use `CalculateExposureVariance(shutterSpeed, aperture, iso)` if performing this in main.
void printAnswer(const float EVoutput) {
	cout << "Exposure Variance Equals:	" << EVoutput << endl	//also print equivalent scenes for this EV.
		<< endl;
}

// Just used to print text really...