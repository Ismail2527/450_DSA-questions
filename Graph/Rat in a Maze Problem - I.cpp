//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& a, 
    int n, vector<string>& ans, string move, 
    vector<vector<int>>& vis) {
    // If we've reached the bottom-right corner of the maze
    if (i == n - 1 && j == n - 1) {
        ans.push_back(move); // Add the current path to the result
        return;
    }

    // Mark the current cell as visited
    vis[i][j] = 1;

    // Downward movement
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
        solve(i + 1, j, a, n, ans, move + 'D', vis);
    }

    // Left movement
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
        solve(i, j - 1, a, n, ans, move + 'L', vis);
    }

    // Right movement
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
        solve(i, j + 1, a, n, ans, move + 'R', vis);
    }

    // Upward movement
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
        solve(i - 1, j, a, n, ans, move + 'U', vis);
    }

    // Backtrack: Unmark the current cell
    vis[i][j] = 0;
}
    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes here
        int n = m.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0)); // Initialize visited array
        if (m[0][0] == 1) { // Start solving from the top-left corner
            solve(0, 0, m, n, ans, "", vis);
        }
        return ans; // Return all found paths
        }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends