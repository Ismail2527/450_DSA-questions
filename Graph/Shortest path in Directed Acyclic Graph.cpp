//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node, unordered_map<int, bool>& vis, stack<int>& st, 
    unordered_map<int, list<pair<int, int>>>& adj) {
    vis[node] = true;
    // Recursively visit all the adjacent nodes
    for (auto it : adj[node]) {
        if (!vis[it.first]) {
            dfs(it.first, vis, st, adj);
        }
    }
    // Push node onto the stack after visiting all its neighbors
    st.push(node);  
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,list<pair<int,int>>>adj;
        //Make Adj list
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        // Topo functions
        stack<int>st;
        unordered_map<int,bool>vis;
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        // 2nd method
        int src = 0;
        vector<int>dest(N,INT_MAX);
        dest[src] = 0;
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(dest[top] != INT_MAX){
                for(auto it : adj[top]){
                    if(dest[top] + it.second < dest[it.first]){
                        dest[it.first] = dest[top]+it.second;
                    }
                }
            }
        }
        
        for(int i=0; i<dest.size(); i++){
            if(dest[i] == INT_MAX){
                dest[i] =-1;
            }
        }
        return dest;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends