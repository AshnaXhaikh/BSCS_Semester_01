#include <iostream>
using namespace std;

// Fucntion Prototypes 
double circleArea(double radius);
double ringArea(double outerRad, double innerRad);

int main(){
	double rad1, rad2;
	
	cout << "Enter Outer Circle Radius: ";
	cin >> rad1; 
	
	cout << "Enter Inner Circle Radius: ";
	cin >> rad2;
	
	// Input Validation 
	if (rad1 <= 0 || rad2 <=0)	{
		cout << "Error: Radii must be positive numbers greater than 0." << endl;
	} 
	else if (rad1 <= rad2) {
		cout << "Error: Outer radius must be strictly GREATER than inner radius.";
	} 
	else {
		double area = ringArea(rad1, rad2);
		cout << "Area of the Ring: " << area << endl; 
	}
	return 0;
}


// Function to calculate circle area 
double circleArea(double radius) {
	return 3.1415926 * radius * radius;
}

// Reusable function to calculate ring area
double ringArea(double outerRad, double innerRad) {
	return circleArea(outerRad) - circleArea(innerRad);
}
