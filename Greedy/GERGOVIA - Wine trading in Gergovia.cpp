#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        // Ensure valid input
        if (n < 2) {
            cout << "Invalid number of inhabitants. Must be at least 2." << endl;
            continue; // Skip to the next iteration
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0; // To store total work done
        long long current_work = 0; // To track current balance

        // Calculate total work required
        for (int i = 0; i < n; i++) {
            current_work += a[i];
            ans += abs(current_work); // Increment total work
        }

        cout << ans << endl; // Output the result for current test case
    }
    return 0;
}