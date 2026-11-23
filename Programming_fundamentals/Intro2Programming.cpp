#include <iostream>
using namespace std;

int main() {
	string name = "Ashna Imtiaz";
	string Id = "BC260404914";
	long num_id = 260404914;
	
	int d5, d6, d7, d8, d9;
	cout << "Student Name: " << name << endl;
	cout << "Student ID: " << Id << endl;
	
	int digit;
	for (int i=0; i<10; i++) {
		if (i==5 || i==6 || i==7 || i==8 || i==9) {
			long divisor = 1;
			for (int j=0; j<(9-i); j++) // Calculate the divisor (10^(9 - i))
			{
				divisor *= 10;
			}
			digit = (num_id / divisor) % 10; 
			
			if (i==5) d5 = digit;
			else if (i==6) d6 = digit;
			else if (i==7) d7 = digit;
			else if (i==8) d8 = digit;
			else if (i==9) d9 = digit;
		}
		
	}
	cout << "\n====== COMMUNITY WATER REFILL DEPOT - DAILY REPORT ======\n" << endl;
	cout << "Order\tQuantity  Package Type\t\tOriginal(Rs.)  Discount  Final(Rs.)" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    
    int q[5] = {d5, d6, d7, d8, d9};
    long collected_amount=0;
	int total_discount=0;
    long total_charges=0;
    int total_quantity=0;
    
    for (int i = 0; i < 5; i++) {
    	
    	int quantity = q[i] * 10;
    	long charges;
    	string containers = "";
    	
    	switch (i) {
    		case 3: case 4:
    			containers = "19-litre container";
    			charges = quantity * 180;
    			break;
    		default:
    			containers = "5-litre container";
    			charges = quantity * 70;
    			break;
		}
		total_quantity += quantity;
		total_charges += charges;
		
		//step 3 discount
		int discount=0;
		int final_price=0;
			
		if (quantity >= 50) { 
			discount = charges * 0.10; // discount = original price * discount rate
			final_price = charges - discount; // sales_price = original price - discount amount
		} else {
			final_price = charges;
		}
		
		collected_amount += final_price;
		total_discount += discount;
		
		cout << q[i] << "\t" << quantity << "\t   " << containers << "\t" << charges << "\t\t" << discount << "\t\t" << final_price;
		cout << endl;
	}
	cout << "------------------------------------------------------------------------------" << endl;
    
    // step 4 status classification
    string status = "";
    if (collected_amount < 15000){
    	status = "LOW SALES";
	} else if (collected_amount>=15000 || collected_amount<=29999){
		status = "NORMAL SALES";
	} else {
		status = "HIGH SALES";
	}
	cout << endl;
	cout << "======= DAILY SUMMARY =======" << endl;
	cout << "Total Containers Supplied\t: Rs. " << total_quantity << endl;
	cout << "Total Original Charges   \t: Rs. " << total_charges << endl;
	cout << "Total Discount           \t: Rs. " << total_discount << endl;
	cout << "Final Amount Collected   \t: Rs. " << collected_amount << endl;
	cout << "Sales Status             \t: " << status << endl;
	return 0;
}
