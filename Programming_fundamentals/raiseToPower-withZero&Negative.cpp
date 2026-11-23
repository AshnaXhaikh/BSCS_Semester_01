#include <iostream>
using namespace std;

// make a such raise to power function that will handle negative power of x, zero and positive power.

// Fucntion prototype
double raiseToPower(double x, int power); 

int main () {
	double base;
	int exponent; 
	
	cout << "Enter base number (x): ";
	cin >> base;
	cout << "Enter an exponenet (n): ";
	cin >> exponent;
	
	cout << base << " ^ " << exponent << " = " << raiseToPower(base, exponent) << endl;
	return 0;
}

// Function definition with zero & negative power handling
double raiseToPower(double x, int power) {
	double result = 1.0;
	int abspower = (power < 0) ? -power: power; // convert -ve exponent to +ve otherwise same ( +ve).

	// calculate x ^ (absPower)
	for (int i=1; i <= abspower; i++) {
		result *= x;
	}

	// If initial power was negative, return the reciprocal (1 / x^n)
	if (power < 0) {
		return 1.0 / result; 
	}
	return result; // Handles +ve powers and zero power (returns 1.0) bcs any number raised to power 0 is just 1.
}
