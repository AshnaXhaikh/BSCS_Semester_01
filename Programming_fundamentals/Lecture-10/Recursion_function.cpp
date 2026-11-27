#include <iostream>
using namespace std;


// function prototype
long factorial(int);


int main() {
	int num = 5;
	cout << "--- Recursion Trace: Factorial(" << num << ") ---" << endl;
	
	// call recursive function
	long result = factorial(num);	
	cout << "\nFinal Answer: " << num << "! = " << result << endl;
	
	return 0;
}


// Recusive Fatorial function
// returns n! = n * (n-1)!
long factorial(int n){ 
	// 1. Base Case: stops the recursive call stack when x in a 0 and 1
	if (n <=1) {
		cout << " [Base Case Reached] factorial (" << n << ") returns 1" << endl;
		return 1;
	}
	
	// 2. Recursive Step: Function calls itself with a smaller input (n - 1)
	cout << "	[PUSHING TO Stack] " << n << " * factorial (" << n - 1 << ")" << endl;
	return n*factorial(n - 1);
}

//--- Recursion Trace: Factorial(5) ---
//        [PUSHING TO Stack] 5 * factorial (4)
//        [PUSHING TO Stack] 4 * factorial (3)
//        [PUSHING TO Stack] 3 * factorial (2)
//        [PUSHING TO Stack] 2 * factorial (1)
// [Base Case Reached] factorial (1) returns 1
//
//Final Answer: 5! = 120
