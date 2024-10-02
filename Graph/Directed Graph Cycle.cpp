//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        // Traverse all adjacent vertices
        for (int neighbor : adj[node]) {
            // If the adjacent node is not visited, recurse on it
            if (!visited[neighbor] && dfs(neighbor, adj, visited, recStack)) {
                return true;
            }
            // If the adjacent node is on the recursion stack, a cycle is found
            else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false; // Remove the node from the recursion stack before returning
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false); // Track visited nodes
        vector<bool> recStack(V, false); // Track nodes in the current recursion stack

        // Check each component of the graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // If a cycle is found, return true
                if (dfs(i, adj, visited, recStack)) {
                    return true;
                }
            }
        }

        return false; // No cycle found
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends