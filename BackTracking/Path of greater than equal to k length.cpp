//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool dfs(int v, int k, vector<pair<int, int>> adj[], vector<bool>& visited) {
        // Base case: if path length k is satisfied, return true
        if (k <= 0) return true;

        // Mark the current node as visited
        visited[v] = true;

        // Explore all adjacent vertices
        for (auto& edge : adj[v]) {
            int u = edge.first;
            int weight = edge.second;

            // If the adjacent vertex is not visited, explore further
            if (!visited[u]) {
                // Check if the current edge leads to a path of required length
                if (dfs(u, k - weight, adj, visited))
                    return true;
            }
        }

        // Backtrack: unmark the current vertex as visited
        visited[v] = false;

        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
        // Create an adjacency list
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < 3 * E; i += 3) {
            int u = a[i];
            int v = a[i+1];
            int weight = a[i+2];
            adj[u].emplace_back(v, weight);
            adj[v].emplace_back(u, weight);
        }    // Initialize visited array
        vector<bool> visited(V, false);

        // Start DFS from vertex 0
        return dfs(0, k, adj, visited);
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends