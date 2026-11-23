#include <iostream>
using namespace std;

// make a such raise to power function that will handle negative power of x, zero and positive power.

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

double raiseToPower(double x, int power) {
	double result = 1.0;
	int abspower = (power < 0) ? -power: power;
	
	for (int i=1; i <= abspower; i++) {
		result *= x;
	}
	
	if (power < 0) {
		return 1.0 / result; 
	}
	return result;
	
}
