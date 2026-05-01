
#include <iostream>
#include "CameraSettings.h"
#include <cmath>
using std::endl;

float CalculateExposureVariance(const float shutterSpeed, const float aperture, const int iso) {
	return std::log2((std::pow(aperture, 2) * 100) / (iso / shutterSpeed));
}

void main()
{

	// Print Copyright 
	std::cout
		<< "Copyright Information:" << endl
		<< "	Author:	Thomas Federico" << endl
		<< "	Last Update:	29 - 4 - 2026" << endl
		<< endl
		<< "	This software, its code, and its future and previous versions are under a CC BY-NC-SA 4.0 license." << endl
		<< "	https://creativecommons.org/licenses/by-nc-sa/4.0/" << endl
		<< endl;

	// Print tutorial
	std::cout
		<< "If you have an image that is perfectly exposed and want to know the EV of the scene, this tool can be useful." << std::endl
		<< endl;

	// Input values
	std::cout
		<< "Input Values:" << endl
		<< "	input shutter speed value (1/[valToInput]):	" << "[INPUTTED VALUE]" << endl
		<< "	input aperture value (f[valToInput]):		" << "[INPUTTED VALUE]" << endl // ask user if they want to input the exact focal ratio, or use a standard value. also inform them, that their camera does not say the actual focal ratio, but in reality is rounded up. Also ask user if they wish to input the diameter of the lens and the focal ratio.
		<< "	input iso:					" << "[INPUTTED VALUE]" << endl
		<< endl;

	//Define Values
	const float inshutterSpeed = 109.0f;	// [1/A]	shutterSpeed = A
	const float inaperture = 1.5f;		// [fA]		aperture = A
	const int iniso = 125; 

	// Display Values
	std::cout
		<< "Inputted Values:" << endl
		<< "	shutterSpeed:	" << "1/" << inshutterSpeed << "	[" << 1/inshutterSpeed << "]" << endl
		<< "	aperture:	f/" << inaperture << "	[" << inaperture << "]" << endl
		<< "	iso:		" << iniso << "	[" << iniso << "]" << endl;


	// Display Equation
	std::cout
		<< "Equation [with values subbed in]:	log2[( " << inaperture << "^2 * 100 ) / ( " << 1/inshutterSpeed << " * " << iniso << " )]" << endl
		<< endl;

	// Calculate Equation
	std::cout
		<< "Calculating Equation:" << endl
		<< "	Calculating..." << endl;
	const float EVoutput = CalculateExposureVariance(inshutterSpeed, inaperture, iniso);
	std::cout
		<< "	Calculated Successfully!" << endl
		<< endl;

	// Display Answer
	std::cout
		<< "Exposure Variance Equals:	" << EVoutput << endl; //also print equivalent scenes for this EV.
}



//adding custom descriptions for each exposure level:
//			when one is added, read a text file containing previously added ones, load each ev into memory, and add the new one into the memory.
//			perform a sorting algorithm, and save the order into the text file.
//
//			you can use the same function above to: add new values, or finding the next closest value by adding the output, sorting, checking the neighboring value, and see which one is closest, and saying that that is the most similar. if the difference is more than a certain threshold, then also print the EV for that setting.