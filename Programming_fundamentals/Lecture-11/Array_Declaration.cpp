#include <iostream>
#include <iomanip>

using namespace std;

//Program 1: Array Declaration, Loop Input, and Average Calculation

// Lecture 11 Best Practice: Define array bounds using const
const int MAX_STUDENTS = 10;

int main() {
	int ages[MAX_STUDENTS];
	int totalAge = 0;
	
	cout << "--- Student Age & Average Processor ---" << endl;
	
	// 1. I/p loop: read ages into array elements ages to ages[2]
	for (int i = 0; i < MAX_STUDENTS; i++) {
		cout << "Enter age for student " << (i + 1) << ": ";
		cin >> ages[i];
	}
	
	// 2. Processing loop: sum array elements
	for (int i = 0; i < MAX_STUDENTS; i++) {
		totalAge += ages[i]; // compound addition operator
	}
	
	double averageAge = (totalAge) / MAX_STUDENTS;
	
	cout << "\n--- Summary ---" << endl;
	cout << "Total Age Sum: " << totalAge << endl;
	cout << fixed << setprecision(2);
	cout << "Average Age: " << averageAge << " years" << endl;
	
	return 0;
}
//Enter age for student 1: 10
//Enter age for student 2: 12
//Enter age for student 3: 13
//Enter age for student 4: 9
//Enter age for student 5: 8
//Enter age for student 6: 7
//Enter age for student 7: 13
//Enter age for student 8: 12
//Enter age for student 9: 9
//Enter age for student 10: 10
//
//--- Summary ---
//Total Age Sum: 103
//Average Age: 10.3 years

//--- Student Age & Average Processor ---
//Enter age for student 1: 3
//Enter age for student 2: 5
//Enter age for student 3: 8
//Enter age for student 4: 9
//Enter age for student 5: 4
//Enter age for student 6: 5
//Enter age for student 7: 12
//Enter age for student 8: 6
//Enter age for student 9: 7
//Enter age for student 10: 3
//
//--- Summary ---
//Total Age Sum: 62
//Average Age: 6.20 years

//--- Summary ---
//Total Age Sum: 51
//Average Age: 5.00 years
