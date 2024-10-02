#include <bits/stdc++.h> 
bool f;

void dfs(int src, int col, vector<int> adj[], vector<int>& vis) {
    vis[src] = col;

    for (auto it : adj[src]) {
        if (vis[it] == -1) {  // If the node is not visited, assign opposite color
            dfs(it, 3 - col, adj, vis);
            if (f == 1) return;  // If already non-bipartite, stop further DFS
        } 
        else if (vis[it] == col) {  // If the neighbor has the same color
            f = 1;
            return;
        }
    }
}

bool isBipartite(int V, vector<int> adj[]) {
    f = 0;
    vector<int> vis(V, -1);  // Initialize all vertices as unvisited (-1)
    
    // Check for all disconnected components
    for (int i = 0; i < V; i++) {
        if (vis[i] == -1) {  // If the node is not visited
            dfs(i, 1, adj, vis);  // Start DFS from this node
            if (f == 1) return false;  // If any component is not bipartite, return false
        }
    }
    return true;  // If all components are bipartite
}
bool twoCliques(int n, vector<vector<int>> &edgeList)
{
	// Write your code here
	// Create adjacency list for the original graph
    unordered_map<int, list<int>> adj;
    for (const auto& edge : edgeList) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create the complement graph
    vector<int> rev[n];
    vector<int> dum(n, 1);  // Initialize all vertices as having connections
    for (int i = 0; i < n; i++) {
        dum[i] = 1;
        for (auto it : adj[i]) {
            dum[it] = 0;  // Mark connected vertices as having no need to connect in the complement graph
        }
        for (int j = 0; j < n; j++) {
            if (i != j && dum[j] == 1) {  // Exclude self-loops and add missing edges
                rev[i].push_back(j);
            }
        }
        fill(dum.begin(), dum.end(), 1);  // Reset dum vector for the next iteration
    }

    // Check if the complement graph is bipartite
    return isBipartite(n, rev);
}