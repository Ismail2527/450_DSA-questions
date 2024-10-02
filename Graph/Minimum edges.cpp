//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
                      
            // create adj with weight 0 and 1
            unordered_map<int,list<pair<int,int>>>adj(n+1);
            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                
                adj[u].push_back({v,0});
                adj[v].push_back({u,1});
            }
            vector<int>vis(n+1,INT_MAX);
            vis[src] = 0;
            
            deque<int>dq;
            dq.push_front(src);
            
            while(!dq.empty()){
                int node = dq.front();
                dq.pop_front();
                
                for(auto it : adj[node]){
                    int neg = it.first;
                    int weg = it.second;
                    
                    if(vis[node]+weg<vis[neg]){
                        vis[neg] = vis[node]+weg;
                        if(weg == 0){
                            dq.push_front(neg);
                        }else{
                            dq.push_back(neg);
                        }
                    }
                }
            }
            return (vis[dst] == INT_MAX)?-1:vis[dst];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends