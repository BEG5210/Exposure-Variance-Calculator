/*
CameraSettings.h

Shortenings:

---	[		WORD	   ][SHORTENING] ---
|	Focal Length			FL			|
|	Apeature Diamater		AD			|
|	F-Stops					FS			|
|	Shutter Speed			SP			|
-----------------------------------------
*/

#pragma once

#include <cmath>

#include "ISODetail.h"

class CameraSettings {
public:
	const float shutterSpeed, FStop;
	const int iso;

	CameraSettings() : CameraSettings(1.0f, 1.0f, 100) {}
	CameraSettings(const float shutterSpeedIn, const float FStopIn) : CameraSettings(shutterSpeedIn, FStopIn, 100) {}

	CameraSettings(const float shutterSpeedIn, const float FStopIn, const int isoIn) :
		shutterSpeed(shutterSpeedIn),
		FStop(FStopIn),
		iso(isoIn)
	{}

private:
	CameraSettings(const float shutterSpeedIn) : CameraSettings(shutterSpeedIn, 1.0f, 100) {}
};

/* 
[INTRO]

This file is a class that contains all of the settings of the camera.


---------------------------------------------------------------------

[A]	Values in class:

	[A]	Values that must be defined and returnable at all times:

	At the very least, the following MUST be defined, as these are the bare minimum values needed to calculate EV:
		F-Stops
		Shutter Speed
		ISO


 *  [B]	Other Values in the class:

	These are Other Values, alongside why they are usefull.
		Focal Length			[BOTH VALUES NEEDED TO CALCULATE F-STOPS ]
		Appeature Diamater		[AND ARE DEPENDENT ON EACH OTHER EXISTING]

		Focal Length and Appeature Diamater are used to calculate the F-Stops.
 *   *  [A]	Discussion on Providing bare minimum values:
			
			Meaning, if you are defining a cameras settings, you must either be able to give one of the following:
			[ NUM ][    DATA VALUES DEFINED IN CLASS	]	[					 DESCRIPTION					]
				1.	F-Stops									F-Stops defined by user
				2.	Focal Length	Appeature Diamater		F-Stop calculated using provided options
				3.	F-Stops			Focal Length			Appeature Diamater calculated using provided values
				4.	F-Stops			Appeature Diamater		Focal Length calculated using provided values

				(For all of these, it is assumed that SP and ISO are given also)

 *   *   *  [A]	Resulting Issues:

				1.	a)	Since no FL and AD are defined, then the values arent defined
				1.	b)	IF no values are defined for FL and AD, then the camera settings class must exist such that two values can be not defined.

 *   *   *  [B]	Solutions:	[*] means that it may not be a fullproof solution or comes with new issues

				1.	a)	a)	Using the fact that FS = FL / AD, you can let 
				1.	b)	a*)	If solution [aa] is used, you could let FL as the intput value for FS.	[*] One value is still allways undefined

 *   *   *   *  [A]	Solutions to the Solutions Issues:

					1.	b)	a)	Change it such that FS is a reference to the equation FL / AD, and let [FL = input value FS] and [AD = 1], due to the properties of defining a value by 1.

[B]	Issues:
		1.	How can you block a class from returning FL and AD if they arent defined [REF: a1]
*/ 