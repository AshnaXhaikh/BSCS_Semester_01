#include <iostream>
using namespace std;

int main() 
{
	int n_people;
	int cost;
	
	n_people = 0;
	
	cout << "Enter Number of Peoples visiting museum: ";
	cin >> n_people;
	
	if (n_people < 10 && n_people > 0) 
	{
		cost = 5 * n_people;
		cout << "Cost is $5 per person." << endl;
		cout << "Therefore cost for " << n_people << " people = $" << cost << endl;
		
	} else if (n_people >= 10){
		cost = 50;
		cout << "Group is 10 or more. Fixed fee applies!\n";
		cout << "Therefore cost for " << n_people << " people = $" << cost << endl;
	} else {
		cout << "Invalid number of people!"<< endl;
	}
	return 0;	
}
