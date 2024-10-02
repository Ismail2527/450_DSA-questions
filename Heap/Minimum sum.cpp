//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        
        // Add digits from the back of both strings
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += num1[i--] - '0';
            if(j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        
        // Reverse the result since we added digits from the back
        reverse(result.begin(), result.end());
        return result;
    }
    string solve(int arr[], int n) {
        // Sort the array
        bool allZeros = true;
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                allZeros = false;
                break;
            }
        }
        
        // If all elements are zero, return "0"
        if (allZeros) return "0";
        sort(arr, arr + n);
        
        // Strings to store the two numbers
        string num1 = "", num2 = "";
        
        // Distribute the digits alternatively
        for(int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                num1 += to_string(arr[i]);
            } else {
                num2 += to_string(arr[i]);
            }
        }
        
        // Adding the two numbers represented by strings
        string result = addStrings(num1, num2);
        
        // Remove leading zeros from the result
        int pos = 0;
        while (pos < result.size() && result[pos] == '0') {
            pos++;
        }
        return result.substr(pos);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends