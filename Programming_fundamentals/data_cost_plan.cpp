#include <iostream>
using namespace std;

int main() 
{
	//The plan charges a base rate of $25 which includes up to 2 gigabytes (GB) of data. 
	//If you use 2 GB or more ($g \ge 2$), you are charged an additional $10 for each extra gigabyte 
	// beyond the 2 GB allowance.
	
	// Use double to support fractional data usage (e.g., 1.5 GB)
	double gb = 0.0;
	double cost = 0.0;
	
	cout << "Enter numbers of gbs you have used: ";
	
	//Input validation check
	if (!(cin >> gb))
	{
		cout << "Error: Invalid input format. Please enter a valid number." << endl;
        return 1; // Exit program with error code
		//return 0; -> Program finished successfully.
		//return 1; -> Program terminated early due to an error (like invalid user input)
	}
	// Edge Case: Negative usage check
    if (gb < 0) 
    {
        cout << "Error: GB usage cannot be negative!" << endl;
    }
    else if (gb <= 2.0) 
    {
        // Covers 0 GB up to 2 GB (Base fee applies)
        cost = 25.0;
        cout << "Base rate applied for " << gb << " GB(s)." << endl;
        cout << "Total Cost = $" << cost << endl;
    }
    else 
    {
        // Covers usage strictly greater than 2 GB
        cost = 25.0 + 10.0 * (gb - 2.0);
        cout << "Base fee ($25) + overage charges applied for " << gb << " GB(s)." << endl;
        cout << "Total Cost = $" << cost << endl;
    }
	return 0;
}
