
#pragma once

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include "Constants.h"

void printCopyright(const bool verbose = false);
void printCopyright(const bool verbose) {
	cout	<< "Copyright Information:" << endl;

	if (verbose) {
		cout	<< "	Author:	Thomas Federico" << endl
				<< "	Last Update:	3 - 5 - 2026" << endl
				<< endl;
	}

	cout	<< "	This software, its code, and its future and previous versions are under a GNU Affero General Public V3.0 License" << endl
			<< endl;
}

void printRepoInf(const string url = repoUrl);
void printRepoInf(const string url) {
	cout	<< "To find out more about this program and the project, visit this link: " << url << endl
			<< endl;
}

void printTutorial(const bool verbose = false);
void printTutorial(const bool verbose) {
	cout	<< "Tutorial:" << endl;

	if (verbose) {
		cout	<< "[VERBOSE] If you have an image that is perfectly exposed and want to know the EV of the scene, this tool can be useful.";
	} else {
		cout	<< "If you have an image that is perfectly exposed and want to know the EV of the scene, this tool can be useful.";
	}

	cout << endl << endl;
}

void printValues(const float shutterSpeed, const float apeature, const int iso, const bool verbose = false);
void printValues(const float shutterSpeed, const float apeature, const int iso, const bool verbose) {
	cout	<< "Inputted Values:" << endl;

	if(verbose) {
		cout	<< "	shutterSpeed:	" << "1/" << shutterSpeed << "	[" << 1 / shutterSpeed << "]" << endl
				<< "	aperture:	f/" << apeature << "	[" << apeature << "]" << endl
				<< "	iso:		" << iso << "	[" << iso << "]";
	} else {
		cout	<< "	[" << shutterSpeed << ",	" << apeature << ",	" << iso << "]";
	}

	cout	<< endl
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
	cout	<< "Exposure Variance Equals:	" << EVoutput << endl	//also print equivalent scenes for this EV.
			<< endl;
}

// Just used to print text really...