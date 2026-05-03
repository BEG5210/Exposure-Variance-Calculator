
#include <iostream>
#include <cmath>
#include "CameraSettings.h"
#include "Printer.h"

using std::endl;
using std::cin;
using std::cout;
using std::string;


float CalculateExposureVariance(const float shutterSpeed, const float aperture, const int iso) {
	return std::log2((std::pow(aperture, 2) * 100) / (iso / shutterSpeed));
}

// Check if input is a valid number
float getValidNumber(string message) {
    float value;
    while (true) {
        cout << message;
        if (cin >> value) {
            return value; // Success! Return the number and exit the loop.
        }
        
        // If we get here, the user typed something wrong
        cout << "Error: Please enter a numeric value." << std::endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void closeProgram() {
	cout << "Press [ENTER] to close.";

	cin.ignore();
	cin.get();

	cout << "Closing . . .";
}

int main()
{

	// Print Copyright information
	printCopyright();

	// Print repo information
	printRepoInf();

	// Print tutorial
	printTutorial();

	// Define Values
	float shutterSpeed;	// [1/A]	shutterSpeed = A
	float aperture;		// [fA]		aperture = A
	int iso; 

	// Input Values
	/* 
		
		Changed this to the below input mehtod.
		Added a method named as getValidNumber(string message) so that it takes the input from the user and asks it again and again 
		if the user is giving wrong inputs and stops only when the user gives correct input. 

			cout	<< "Input Values:" << endl;
			cout 	<< "	input shutter speed value (1/[valToInput]):	"; cin >> inshutterSpeed;
			cout	<< "	input aperture value (f[valToInput]): "; cin >> inaperture;	// ask user if they want to input the exact focal ratio, or use a standard value. also inform them, that their camera does not say the actual focal ratio, but in reality is rounded up. Also ask user if they wish to input the diameter of the lens and the focal ratio.
			cout	<< "	input iso: "; cin >> iniso;

		Now even though it completely does not allow something like "abc", "abc1", "a1bc", but it will allow strings such as
		"1abc" or "1abc2" by only taking 1 as the input for the variable and truncating the other left out "abc".

	*/

	shutterSpeed = getValidNumber("    input shutter speed value (1/[valToInput]): ");
    aperture     = getValidNumber("    input aperture value (f[valToInput]): ");// ask user if they want to input the exact focal ratio, or use a standard value. also inform them, that their camera does not say the actual focal ratio, but in reality is rounded up. Also ask user if they wish to input the diameter of the lens and the focal ratio.
    iso          = (int)getValidNumber("    input iso: ");
	cout	<< endl;

	// Display Values
	printValues(shutterSpeed, aperture, iso);

	// Display Equation
	printEquation(shutterSpeed, aperture, iso);

	// Calculate Equation
	cout	<< "Calculating Equation:" << endl
			<< "	Calculating..." << endl;
	const float EVoutput = CalculateExposureVariance(shutterSpeed, aperture, iso);
	cout	<< "	Calculated Successfully!" << endl
			<< endl;

	// Display Answer
	printAnswer(EVoutput);

	// Close Program
	closeProgram();

	return 0;
}

// Eventially, functions outside of main will be in a seperate file


/*	adding custom descriptions for each exposure level:
 *		when one is added, read a text file containing previously added ones, load each ev into memory, and add the new one into the memory.
 *		perform a sorting algorithm, and save the order into the text file.
 *
 *		you can use the same function above to: add new values, or finding the next closest value by adding the output, sorting, checking the neighboring value, and see which one is closest, and saying that that is the most similar. if the difference is more than a certain threshold, then also print the EV for that setting.
 *
 *	NOTES:
 *		Eventually, each print section should be within the print class (or al least a seperate class) as its own function.
 */
