//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        if(arr.size() == 1)return 0;
        vector<int>v;
        long long ans =0;
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        while(i<=j){
            //if(i==j) v.push_back(arr[i++]);
            v.push_back(arr[i++]);
            v.push_back(arr[j--]);
        }
        
        for (int j = 0; j < v.size() - 1; j++) { // corrected to v.size() - 1 to avoid out-of-bounds
            ans = ans + abs(v[j] - v[j + 1]);
        }
        ans = ans + abs(v[0] - v[v.size() - 1]); // final calculation
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends