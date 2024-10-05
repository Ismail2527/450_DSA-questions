//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
        //base case
        if(i == str1.size()){
            return str2.size() - j;
        }
        if(j == str2.size()){
            return str1.size() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans =0;
        if(str1[i] == str2[j]){
            return solve(str1,str2,i+1,j+1,dp);
        }else{
            //insertion
            int in = 1+solve(str1,str2,i+1,j,dp);
            //Deletion
            int del =  1+solve(str1,str2,i,j+1,dp);
            //update
            int up = 1+solve(str1,str2,i+1,j+1,dp);
            ans = min(in,min(del,up));
        }
        return dp[i][j] =ans;
    }
    int editDistance(string str1, string str2) {
        // Code here
        vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
        return solve(str1,str2,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends