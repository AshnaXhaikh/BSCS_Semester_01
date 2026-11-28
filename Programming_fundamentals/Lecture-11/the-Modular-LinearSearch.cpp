#include <iostream> 
using namespace std; 

const int SIZE = 5;

// function prototypes
void printArr(const int arr[], int size);
int linearSearch(const int arr[], int size, int target);

int main () {
	int array[SIZE] = {1, 3, 5, 7, 9};
	int target; 
	
	// 1. Take the target integer
	cout << "Enter target integer: "; 
	cin >> target;
	
	// 2. linear search througn function call 
	int foundindex = linearSearch(array, SIZE, target);
	
	// 3. Output the result
	if (foundindex != -1) {
		cout << "Target: " << target << " found at index: [" << foundindex << "] ";
	} else {
		cout << "Target: " << target << " was not found !";
	}
	cout << endl;
	
	
	// 4. Display the array
	cout << "Array: "; 
	printArr(array, SIZE);
	
	
	return 0;
}

// Function Definitions

// Helper function ( display array elements )
void printArr(const int arr[], int size) {
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}
// find and return index ( single responsibility )
int linearSearch(const int arr[], int size, int target){
	for (int i = 0; i < size; i++){
		if (arr[i] == target) {
			return i; // early exit as soon as target found
		}
	}
	return -1; // if element is not found return -1
}

//Enter target integer: 3
//Target: 3 found at index: [1]
//Array: 1 3 5 7 9

//Enter target integer: 10
//Target: 10 was not found !
//Array: 1 3 5 7 9
