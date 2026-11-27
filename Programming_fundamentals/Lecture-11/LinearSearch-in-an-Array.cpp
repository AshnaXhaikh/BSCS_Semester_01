#include <iostream> 
using namespace std; 

//Program 3: Linear Search in an Array
//Concept: Scans an array sequentially to find a target value z, using a flag variable and break to exit the loop as soon as the target is located

const int ARRAY_SIZE = 10;

int main() {
	int data[ARRAY_SIZE] = {15, 42, 8, 23, 91, 56, 34, 77, 12, 60};
	int target; 
	int foundIndex = -1;
	bool isFound = false; 
	
	cout << "--- Linear Search Demo ---" << endl;
	cout << "Array contents: "; 
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << data[i] << " ";
	}
	cout << endl; 
	
	cout << "Enter target integer to search: ";
	cin >> target;
	
	// Linear search loop
	for (int i=0; i < ARRAY_SIZE; i++) { 
		if (data[i] == target) {
			isFound = true;
			foundIndex = i;
			break;   // Immediately exit loop once found
		}
	}
	
	if (isFound) {
		cout << "Result: Found target " << target << " at index [" << foundIndex << "]." << endl;
	} else {
		cout << "Result: Target " << target << " was NOT found in the array." << endl;
	}
	return 0;
}

