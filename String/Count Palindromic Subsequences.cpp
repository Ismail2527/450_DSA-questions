//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    const long long int MOD = 1e9 + 7;  
    long long int solve(int i, int j, string &s, vector<vector<long long int>> &dp) {
        // base case
        if (i > j) return 0;
        if (i == j) return 1;
        
        // check if already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        // if characters at i and j are the same
        if (s[i] == s[j]) {
            dp[i][j] = (solve(i + 1, j, s, dp) + solve(i, j - 1, s, dp) + 1)%MOD;
        } else {
            dp[i][j] = (solve(i + 1, j, s, dp) + solve(i, j - 1, s, dp) -
            solve(i + 1, j - 1, s, dp)+MOD)%MOD;
        }
        return dp[i][j];
    }
    long long int  countPS(string str)
    {
       //Your code here
       int i=0;
       int n=str.size();
       vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
       return solve(i,n-1,str,dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends