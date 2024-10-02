//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool f;
    void dfs(int src, int par, int col, vector<int> adj[], vector<int>& vis) {
        vis[src] = col;
        
        for (auto it : adj[src]) {
            if (vis[it] == -1) {  // If the node is not visited, assign opposite color
                dfs(it, src, 3 - col, adj, vis);
                if (f == 1) return;  // If already non-bipartite, stop further DFS
            } 
            else if (vis[it] == col) {  // If the neighbor has the same color
                f = 1;
                return;
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	     f = 0;
        vector<int> vis(V, -1);  // Initialize all vertices as unvisited (-1)
        
        // Check for all disconnected components
        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {  // If the node is not visited
                dfs(i, -1, 1, adj, vis);  // Start DFS from this node
                if (f == 1) return false;  // If any component is not bipartite, return false
            }
        }
        return true;  // If all components are bipartite
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends