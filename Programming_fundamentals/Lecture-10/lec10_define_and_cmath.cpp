#include <iostream>
#include <cmath> // Standard math library (SQR, pow, log, sin, cos)


using namespace std;

// Preprocessor Directive: Defines a global constant symbol 'PI'
// During preprocessing, 'PI' is replaced by 3.1415926 before compilation
#define PI 3.1415926

// Function Prototypes (In practice, these are placed in a .h header file)
double calculateCircleArea(double radius);
double calculateCylinderVolume(double radius, double height);

int main() {
    double r = 5.0;
    double h = 10.0;

    cout << "--- Preprocessor & Math Library Demo ---" << endl;
    cout << "Radius: " << r << ", Height: " << h << endl;
    cout << "Circle Area: " << calculateCircleArea(r) << endl;
    cout << "Cylinder Volume: " << calculateCylinderVolume(r, h) << endl;
    
    // Using built-in <cmath> functions as discussed in Lecture 10
    cout << "Square root of 25: " << sqrt(25.0) << endl;
    cout << "2 raised to power 3 (pow): " << pow(2.0, 3.0) << endl;

    return 0;
}

// Function Definitions
double calculateCircleArea(double radius) {
    return PI * pow(radius, 2); //  we are using here the preprocessor constant PI here
}

double calculateCylinderVolume(double radius, double height) {
    return calculateCircleArea(radius) * height; // Reuses function
}
