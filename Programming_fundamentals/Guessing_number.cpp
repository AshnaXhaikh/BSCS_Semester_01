#include <iostream>
using namespace std;

int main() {
	int z, i;
	int a[100];
	
	//populate the array with values 0 to 99
	for (i = 0; i < 100; i++){
		a[i] = i;
	}
	
	// Ask the user to enter a number to guess
	cout << "please enter a positive integer: ";
	cin >> z;
	// 3. Linear search using a flag variable
    int found = 0;  // 0 means not found yet
    
    for (i = 0; i < 100; i++){
    	if (z == a[i]) {
            found = 1;  // Raise the flag: number found!
            break;      // Exit the loop immediately
        }
	}
	
	if (found == 1) {
		cout << "we found the integer at position " << i << endl;
	} else {
		cout << "the number was not found" << endl;
	}
	
	return 0;
}
