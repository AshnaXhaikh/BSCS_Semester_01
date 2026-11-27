#include <iostream> 
using namespace std; 

//Program 4: Array Copying & Sum of Squares Computation
//Concept: Demonstrates copying elements from one array to another using a loop (b[i] = a[i]) and performing mathematical operations on array elements.

const int SIZE = 5;

int main() {
	int sourceArray[SIZE] = {2, 4, 6, 8, 10};
	int destinationArray[SIZE];
	int sumOfSquares = 0;
	
	cout << "=== Array Copying & Transformation ===" << endl;
	
	// 1. Element-by-element array copy
	cout << "Destination Array: " ;
	for (int i=0; i < SIZE; i++) {
		destinationArray[i] = sourceArray[i];
		cout << destinationArray[i] << " ";
	}
	
	// 2. Compute sum of squares on copied elements
	for (int i=0; i < SIZE; i++) {
		sumOfSquares += (destinationArray[i] * destinationArray[i]);
	}
	
	cout << "\nSource Array:	"; 
	for (int i=0; i < SIZE; i++) cout << sourceArray[i]	 << " "; 
	cout << endl;
	
	cout << "Sum of Squares:	" << sumOfSquares << endl;
	
	return 0;
}

//=== Array Copying & Transformation ===
//Destination Array: 2 4 6 8 10
//Source Array:   2 4 6 8 10
//Sum of Squares: 220


