#include <iostream>
using namespace std;

//Challenge 3: Filtering Array Elements
//Goal: Practice copying matching elements from a source array into a destination array (e.g., counting and extracting even numbers).

const int MAX = 6; 

// PROTOTYPES
void printArray(const int arr[], int size);

// copies even numbers from source to dest returns how many were copied
int extractEvens(const int arr[], int size, int dest[]);


int main() {
	int original[MAX] = {7, 14, 21, 28, 35, 42};
	int evensOnly[MAX]; // destination array to hold filtered numbers
	
	cout << "Original Array: ";
	printArray(original, MAX);
	
	// Filter and copy matching elements into destination array
	int count = extractEvens(original, MAX, evensOnly);
	
	cout << "Destination Array (Evens Only): " ;
	printArray(evensOnly, count); // Print ONLY the valid copied elements
	
	return 0;
}

// helper function 
void printArray(const int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int extractEvens(const int arr[], int size, int dest[]) {
	int destIndex = 0; // Tracks index in dest array
	
	for (int i = 0; i < size; i++) {
		if (arr[i] % 2 == 0) {
			dest[destIndex] = arr[i];  // copy even numbers
			destIndex++;			   // move to next index in dest array
		}
	}
	return destIndex; // return the count of copied elements
}
// OUTPUT
//Original Array: 7 14 21 28 35 42
//Destination Array (Evens Only): 14 28 42

	
