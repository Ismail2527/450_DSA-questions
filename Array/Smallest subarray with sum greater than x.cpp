//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int cs = 0, ml = INT_MAX, s = 0, e = 0;
        while (e < n) {
            while (cs <= x && e < n) {
                cs = cs + arr[e++];
            }
            while (cs > x && s < n) {
                if (e - s < ml) {
                    ml = e - s;
                }
                cs = cs - arr[s++];
            }
        }
        return (ml == INT_MAX) ? 0 : ml;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends