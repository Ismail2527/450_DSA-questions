//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // Using Prim's algorithm to find the MST weight
        
        // Min-heap to store the edge weight and the corresponding node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Vector to keep track of visited nodes (whether they are in MST or not)
        vector<bool> inMST(V, false);
        
        // Vector to store the minimum weight to connect each node
        vector<int> key(V, INT_MAX);
        
        // Start the algorithm from node 0
        pq.push({0, 0}); // {weight, node}
        key[0] = 0;
        
        int totalWeight = 0;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            // If the node is already included in MST, continue
            if (inMST[u]) continue;
            
            // Add the node to the MST and add its weight to totalWeight
            inMST[u] = true;
            totalWeight += wt;
            
            // Traverse the adjacency list of the node u
            for (auto &it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                
                // If v is not in MST and the current weight is smaller than the previously recorded weight
                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }
        
        return totalWeight;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends