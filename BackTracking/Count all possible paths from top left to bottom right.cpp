//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1e9+7;
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<int>> paths(m, vector<int>(n, 0));
        
        // initialize the first row and first column to 1
        for (int i = 0; i < m; i++) {
            paths[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            paths[0][j] = 1;
        }
        
        // fill the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                paths[i][j] = (paths[i-1][j] + paths[i][j-1]) % mod;
            }
        }
        
        return paths[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends