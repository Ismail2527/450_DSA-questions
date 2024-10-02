#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Depth-first search to find the size of each connected component
void dfs(int node, vector<int>& vis,  unordered_map<int,list<int>>&adj, int& component_size) {
    vis[node] = 1;         // Mark node as visited
    component_size++;     // Increment size for this connected component
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, vis, adj, component_size);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>>& astronaut) {
    unordered_map<int,list<int>>adj(n);  // Adjacency list to store astronaut pairs
    
    // Build the adjacency list
    for (const auto& pair : astronaut) {
        int u = pair[0];
        int v = pair[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vis(n, 0); // To track visited astronauts
    vector<int> component_sizes;  // To store the sizes of connected components
    
    // Traverse each astronaut to find the components
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int component_size = 0;  // Size of the current connected component
            dfs(i, vis, adj, component_size);  // Perform DFS
            component_sizes.push_back(component_size);  // Store the component size
        }
    }
    
    // Calculate the total number of valid pairs (n * (n-1) / 2)
    int total_pairs = n * (n - 1) / 2;
    
    // Subtract the pairs within the same components
    for (int size : component_sizes) {
        int same_component_pairs = size * (size - 1) / 2;
        total_pairs -= same_component_pairs;
    }
    
    return total_pairs;  // Return the number of valid pairs
}

int32_t main() {
    int n, p;
    cin >> n >> p;  // Number of astronauts and number of pairs
    
    vector<vector<int>> astronaut(p, vector<int>(2));
    for (int i = 0; i < p; i++) {
        cin >> astronaut[i][0] >> astronaut[i][1];
    }
    
    int result = journeyToMoon(n, astronaut);
    cout << result << endl;  // Output the result
    
    return 0;
}
