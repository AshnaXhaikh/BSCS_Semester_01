#include <iostream>
using namespace std;
## Variable Scope & Visibility (Global, Local, and Block Scope)
Concept: Demonstrates how variables behave across File/Global Scope, Function Scope, and Block Scope ({ }), illustrating why the instructor advises minimizing global variables to prevent unintended side-effects.

// ## Call by Value vs. Call by Reference
// Concept: Contrasts default Call by Value (passing copies so original caller variables remain untouched) with Call by Reference (passing variable addresses/aliases so function modifications directly alter caller variables).


// Function prototypes
void squareByValue(double);
void squareByReference(double&); // without & the linked would be failed 
void squareByPointer(double*);  // it can be double *  or double *ptr or double* ptr

int main() {
	double n1, n2, n3;
	n1 = n2 = n3 = 4;
	
	cout << "--- Call by Value vs. Call by Reference --- " << endl;
	
	// Test Call by Value
	cout << "\n1. CALL BY VALUE:" << endl;
	cout << "	Before call: num1 = " << n1 << endl;
	squareByValue(n1);
	cout << "	After call : num1 = " << n1 << " (Unchanged)" << endl;
	
	// Test Call by Reference (C++ & syntax)
	cout << "\n1. CALL BY REFERENCE (&):" << endl;
	cout << "	Before call: num2 = " << n2 << endl;
	squareByReference(n2);
	cout << "	After call : num2 = " << n2 << " (Modified in main!)" << endl;
	
	// Test call by Reference (Pointer / Address syntax)
	cout << "\n3. CALL BY REFERENCE (POINTER *): " << endl;
	cout << "	Before call: num3 = " << n3 << endl;
	squareByPointer(&n3); // Pass adress of n3
	cout << "	After call: num3 = " << n3 << " (Modified in main!)" << endl;
	
	return 0;
}

// 1. call by value: operates on a local copy of x 
void squareByValue(double x) {
	x *= x; 	// Modifies ONLY the local copy inside squareByValue
	cout << " [Inside squareByValue] x = " << x << endl; 
}

// 2. Call by Reference (C++ & Reference): Operate directly original memory
void squareByReference(double &x) {
	x *= x;		// Directly modifies the variable in caller scope (main)
	cout << " [Inside squareByReference] x = " << x << endl;
}

// 3. Call by Referecne (Pointer / Address) : Passing memory address as shown in lecture 10
void squareByPointer(double *ptr) {
	*ptr = (*ptr) * (*ptr); // Dereferences pointer and updates caller variable
	cout << " [Inside squareByPointer] *ptr  = " << *ptr << endl;
}
