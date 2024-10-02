//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
        int ans =0;
        int n = arr.size();
        int maxrange=0;
        int longrange=0;
        
        for(int i=0; i<n; i++){
            
            if(i+arr[i] > longrange){
                longrange = i+arr[i];
            }
            if( i == maxrange){
                ans++;
                maxrange = longrange;
                if(longrange >= n-1){
                    return ans;
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends