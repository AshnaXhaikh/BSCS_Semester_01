#include <iostream>
using namespace std;

int main() {
	string name = "Ashna Imtiaz";
	string ID = "BC260404914";
	long num_id = 260404914;
	
	int digit=0;
	int d2, d4, d5, d6, d8;
	
	cout << "Student Name: " << name << endl;
	cout << "Student ID: " << ID << endl;
	
    // Loop through each position from 1 to 9 (left to right)	
	for (int i=1; i<=9; i++)
	{
		// Check if the current position is one of the required ones
		if (i==2 || i==4 || i==5 || i==6 || i==8)
		{
			long divisor = 1;
			for (int j=0; j<(9-i); j++) // Calculate the divisor (10^(9 - i))
			{
				divisor *= 10;
			}
			digit = (num_id / divisor) % 10; 
			
			if (i==2) d2 = digit; 
			else if (i==4) d4 = digit;
			else if (i==5) d5 = digit;
			else if (i==6) d6 = digit;
			else if (i==8) d8 = digit;
		}
	}
	cout << "Extracted digits: " << d2 << ", " << d4 << ", " << d5 << ", " << d6 << ", " << d8;
	cout << endl;
	
	cout << "----- University IT Helpdesk WorkLoad Report -----" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "Unit\t\t\tTotal Tickets\tResolution Time\tStatus" << endl;
    cout << "------------------------------------------------------------------" << endl;
    
    // loop through the desks
    int tickets[5] = {d2, d4, d5, d6, d8};
    string units[5] = {
		"Network Support:",
		"Computer Lab Support:",
		"LMS Support:",
		"Account Support:", 
		"Hardware Support:"
	};
	
	int lightCount, moderateCount, heavyCount;
	
	for (int i=0; i<5; i++) {
		int t = tickets[i];
		int resTime = t * 20;
		string status = "";
		
		// step 5 classification
//		if (t >= 7) {
//			status = "HEAVY";
//			heavyCount++;
//		} else if (t >= 4) {
//			status = "MODERATE";
//			moderateCount++;
//		} else {
//			status = "LIGHT";
//			lightCount++;
//		}
		
		switch (t) {
			case 7: case 8 : case 9:
				status = "HEAVY";
				heavyCount++;
				break;
			case 4: case 5: case 6:
				status = "MODERATE";
				moderateCount++;
				break;
			default: // fewer than 4
				status = "LIGHT";
				lightCount++;
				break;
		}
		cout << units[i];
		if (units[i].length() < 16) cout << "\t"; // tab adjustment
		cout << "\t" << t << "\t\t" << resTime << "\t\t" << status << endl;
	}
	
	cout << "------------------------------------------------------------------" << endl;
    
	// step 6 summary output
	cout << "======== SUMMARY ========" << endl;
	cout << "LIGHT desks\t : " << lightCount << endl;
	cout << "MODERATE desks\t : " << moderateCount << endl;
	cout << "HEAVY desks\t : " << heavyCount << endl;
	cout << "------------------------------------------------------------------" << endl;
    
	return 0;
}
