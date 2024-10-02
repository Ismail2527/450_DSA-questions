//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i,int j,int vis[502][502],int n,int m,vector<vector<char>>&grid){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j] == '0'){
            return;
        }
        if(!vis[i][j]){
            vis[i][j] = 1;
            dfs(i+1,j,vis,n,m,grid);
            dfs(i-1,j,vis,n,m,grid);
            dfs(i,j+1,vis,n,m,grid);
            dfs(i,j-1,vis,n,m,grid);
            dfs(i+1,j+1,vis,n,m,grid);
            dfs(i-1,j-1,vis,n,m,grid);
            dfs(i-1,j+1,vis,n,m,grid);
            dfs(i+1,j-1,vis,n,m,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int vis[502][502] = {0};
        
        int c =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,vis,n,m,grid);
                    c++;
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends