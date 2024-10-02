//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    //Function to perform DFS traversal
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;
        for (auto neighbor : adj[node]) {
            if (neighbor == parent) continue; // Skip the parent edge
            if (!visited[neighbor]) {
                dfs(neighbor, node, adj, visited);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        // Mark all vertices as not visited
        vector<int> visited(V, 0);

        // Remove edge (c, d) temporarily
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

        // Perform DFS from one of the vertices (either c or d)
        dfs(c, -1, adj, visited);

        // Restore the edge (c, d)
        adj[c].push_back(d);
        adj[d].push_back(c);

        // Check if vertex d is still reachable from vertex c
        return !visited[d];
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends