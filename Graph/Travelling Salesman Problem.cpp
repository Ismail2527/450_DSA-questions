//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
vector<vector<int>> dp;
    
    int solve(int i, int mask, int n, vector<vector<int>>& cost) {
        // If all nodes are visited, return cost to go back to starting node
        if (mask == (1 << n) - 1) return cost[i][0];
        
        // If this state has been solved before, return the result
        if (dp[i][mask] != -1) return dp[i][mask];
        
        int ans = 1e9 + 7;
        
        // Try to go to every other node that hasn't been visited
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) continue; // Skip if node j is already visited
            ans = min(ans, cost[i][j] + solve(j, mask | (1 << j), n, cost));
        }
        
        return dp[i][mask] = ans;
    }
int total_cost(vector<vector<int>>cost){
    // Code here
        int n = cost.size();
        dp = vector<vector<int>>(n, vector<int>(1 << n, -1));
        return solve(0, 1, n, cost);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends