#include <iostream>
using namespace std;

// Global variable 
int countVal = 100;

void demonstrateScope() {
	// Local variable ( local scope )
	int countVal = 20;   // Local variable hides the global variable 'countVal'
	cout << "[Inside function] local countVal = " << countVal << endl;
}

int main () {
	cout << "--- Variable Scope & Visibility Demo --- " << endl;
	cout << "[Main - Start] Global countVal = " << countVal << endl;
	
	demonstrateScope(); // if we call this function after 'cout' then it will  throw error
	// because cout wants output to display on screen whereas 'void' doesn't return any output
	
	// Black Scope Demo
	{
		int blockVar = 50; // local strictly to this block
		int countVal = 5;  // Hides outer countVal within this block ONLY
		cout << "[Inside Block] Inner countVal = " << countVal << endl;
		cout << "[Inside Block] blockVar = " << blockVar << endl;
	}
	// blockVar is now out of scope and no longer exists here!
	
	cout << "[Main - End] Global countVal remains = " << countVal << endl;
	
	return 0;
}

// // Output 
// --- Variable Scope & Visibility Demo ---
// [Main - Start] Global countVal = 100
// [Inside function] local countVal = 20
// [Inside Block] Inner countVal = 5
// [Inside Block] blockVar = 50
// [Main - End] Global countVal remains = 100
