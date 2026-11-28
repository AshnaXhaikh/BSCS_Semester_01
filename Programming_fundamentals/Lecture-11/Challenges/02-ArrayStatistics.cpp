#include <iostream>
#include <iomanip>
using namespace std;

//Challenge 2: Array Statistics (Separate Math from Output)
//Goal: Write a program that calculates the maximum value and total sum of an array. 
//Notice how findMax and calculateSum do not use cout—they simply compute and return the value back to main().

const int CAPACITY = 6; 
// function prototypes 
int findMax(const int arr[], int size); 
int calculateSum(const int arr[], int size); 

int main () {
	int scores[CAPACITY] = {91.72, 75.3, 100, 68.68, 95.5, 98.35};
	int highestScore = findMax(scores, CAPACITY);
	int totalScore = calculateSum(scores, CAPACITY);
	double avgScore = static_cast<double>(totalScore) / CAPACITY; 
	
	cout << "==== Result ===="<< endl; 
	cout << "Highest Score : " << highestScore << endl;
	cout << "Total Sum     : " << totalScore << endl;
	cout << "Class Average : " << avgScore << endl;
	
	return 0;
}

//1. find maximum value
int findMax(const int arr[], int size) {
	int maxVal = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	return maxVal;
}

int calculateSum(const int arr[], int size) {
	int sum = 0;
	for (int i=0; i < size; i++) {
		sum += arr[i]; 
	}
	return sum;
}

//==== Result ====
//Highest Score : 100
//Total Sum     : 527
//Class Average : 87.8333
