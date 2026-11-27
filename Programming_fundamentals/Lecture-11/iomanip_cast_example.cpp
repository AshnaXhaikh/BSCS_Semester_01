#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int sum = 7;
    int count = 2;

    cout << "--- 1. Basic Division ---" << endl;
    cout << "Without static_cast<double>: " << sum / count << endl;
    cout << "With static_cast<double>:    " << static_cast<double>(sum) / count << endl;

    cout << "\n--- 2. Formatted with fixed & setprecision(2) ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Without static_cast<double>: " << sum / count << endl;
    cout << "With static_cast<double>:    " << static_cast<double>(sum) / count << endl;

    cout << "\n--- 3. Original Variables Stay Unchanged ---" << endl;
    cout << "sum is still int (7):   " << sum << endl;
    cout << "count is still int (2): " << count << endl;

    return 0;
}

// --- 1. Basic Division ---
// Without static_cast<double>: 3
// With static_cast<double>:    3.5

// --- 2. Formatted with fixed & setprecision(2) ---
// Without static_cast<double>: 3
// With static_cast<double>:    3.50

// --- 3. Original Variables Stay Unchanged ---
// sum is still int (7):   7
// count is still int (2): 2
