#include <iostream>
using namespace std;

//# practice 1 (CALL BY VALUE)
//Question: What will be printed for num after the function call?
//Answer: num remains 5.
//Explanation: A copy of num (5) was passed to parameter x
//. Adding 10 changed x to 15 inside modifyValue(), but the original variable num in main() was left untouched
void modifyValue(int);

//# PRACTICE 2 (CALL BY REFERENCE)
void modifyReference(int&);

// # PRACTICE 3 (CALL BY VALUE)
void swapVal(int a, int b);

// # PRACTICE 4 (CALL BY REFERENCE)
void swapRef(int &a, int &b);

int main(){
	int num = 5;
	int x = 10, y = 20;
	
	cout << "before calling function: num = " << num << endl;
	
	cout << "INSIDE modifyValue function calling function: ";
	modifyValue(num);
	
	cout << "after calling function: num =  " << num << endl;
	
	cout << "INSIDE the modifyreference function: num = ";
	modifyReference(num);
	cout << endl;
	
	cout << "after calling function: num =  " << num << endl;
	
	cout << "Swaping values of x = " << x << " and y = " << y << " INSIDE SwapVal function: ";
	swapVal(x, y);
    
    cout << "OUTSIDE of SwapVal function: ";
    cout << "x = " << x << ", y = " << y << endl; // What is printed?
    
    cout << "INSIDE of SwapRef function: ";
    swapRef(x, y);
    
    cout << "OUTSIDE of SwapRef function: ";
    cout << "x = " << x << ", y = " << y; // What is printed?
}

void modifyValue(int x) {
	x = x + 10;
	cout << "inside function the modified value is: " << x << endl;
}
void modifyReference(int &x) {
	x = x + 10;
	cout << x ;
}

void swapVal(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	cout << "x = " << a << " and y = " << b << endl;
}

void swapRef(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
	cout << "x = " << a << " and y = " << b << endl;
}
