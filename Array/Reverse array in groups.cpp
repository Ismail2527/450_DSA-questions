//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void reverseInGroups(vector<long long int> &arr, int k) {
        // code here
        // Traverse the array in chunks of size k
        for (int i = 0; i < arr.size(); i += k) {
            int left = i;
            // Ensure the right index does not go out of bounds
            int right = min(i + k - 1, (int)arr.size() - 1);
            
            // Reverse the group
            while (left < right) {
                swap(arr[left++], arr[right--]);
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<long long int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        ob.reverseInGroups(arr, k);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends