#include <iostream>
using namespace std;

//Program 2: Sentinel-Controlled Array Input & Bounds Checking
//Concept: Dynamically reads positive numbers into an array until -1 is entered or array capacity is reached, using a do-while loop.

const int CAPACITY = 100;

int main() {
	int numbers[CAPACITY];
	int inputVal;
	int count = 0;
	
	cout << "--- Sentinel Controlled Array Input ---" << endl;
	cout << "Enter positive integers (enter -1 to stop, max 100 entries): " << endl;
	
	// Do-while loop executes at least once to read input 
	do {
		cout << "Enter value [" << count << "]: ";
		cin >> inputVal;
		
		if (inputVal != -1) {
			numbers[count] = inputVal; // Assign to array element
			count++;				   // Increment stored count
		}
	} while (inputVal != -1 && count < CAPACITY);
	
	cout << "\nTotal valid numbers entered: " << count << endl;
	cout << "Stored elements: ";
	for (int i = 0; i < count; i++) {
		cout << numbers[i] << " "; 
	}
	cout << endl;
	
	return 0;
}

//--- Sentinel Controlled Array Input ---
//Enter positive integers (enter -1 to stop, max 100 entries):
//Enter value [0]: 3
//Enter value [1]: 2
//Enter value [2]: 1
//Enter value [3]: 4
//Enter value [4]: 5
//Enter value [5]: 89
//Enter value [6]: 876
//Enter value [7]: 23
//Enter value [8]: -8
//Enter value [9]: -7
//Enter value [10]: -2
//Enter value [11]: -1
//
//Total valid numbers entered: 11
//Stored elements: 3 2 1 4 5 89 876 23 -8 -7 -2
