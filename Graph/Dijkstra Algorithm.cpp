//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V, INT_MAX);
        
        // Set to store pairs of (distance, vertex)
        set<pair<int, int>> st;
        
        // Initialize the source vertex distance
        dist[S] = 0;
        st.insert({0, S});
        
        while(!st.empty()){
            // Fetch the top record
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            
            // Remove the top record
            st.erase(st.begin());
            
            // Traverse through the neighbors of topNode
            for(auto neighbour : adj[topNode]){
                int v = neighbour[0];
                int weight = neighbour[1];
                
                // Check if the current path is shorter
                if(nodeDistance + weight < dist[v]){
                    auto record = st.find({dist[v], v});
                    
                    // If record is found, erase it
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    // Update the distance
                    dist[v] = nodeDistance + weight;
                    
                    // Insert the new record into the set
                    st.insert({dist[v], v});
                }
            }
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends