//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	// DFS to fill the stack based on finishing times
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }
        st.push(node);  // Push the node after visiting all its neighbors
    }
    
    // DFS on the transposed graph
    void reverseDFS(int node, vector<vector<int>>& transposedAdj, vector<bool>& visited) {
        visited[node] = true;
        for (auto neighbor : transposedAdj[node]) {
            if (!visited[neighbor]) {
                reverseDFS(neighbor, transposedAdj, visited);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // Step 1: Perform DFS on the original graph and push nodes to the stack
        stack<int> st;
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }
        
        // Step 2: Transpose the graph (reverse the edges)
        vector<vector<int>> transposedAdj(V);
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                transposedAdj[neighbor].push_back(i);
            }
        }
        
        // Step 3: Perform DFS on the transposed graph in the order of the stack
        fill(visited.begin(), visited.end(), false);  // Reset the visited array
        int sccCount = 0;  // To count the number of strongly connected components
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            if (!visited[node]) {
                sccCount++;  // We found one new SCC
                reverseDFS(node, transposedAdj, visited);
            }
        }
        
        return sccCount;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends