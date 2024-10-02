//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int help(int count,int taken,int v,int n,int m,vector<int> adj[],vector<int> mm){
            if(count==m){
                return taken;
            }
            if(v==n+1){
                return INT_MAX;
            }
            int a=INT_MAX,b=INT_MAX;
            a = help(count,taken,v+1,n,m,adj,mm);
            count+=adj[v].size();
            for(auto x:adj[v]){
                if(mm[x])count--;
            }
            mm[v]++;
            b = help(count,taken+1,v+1,n,m,adj,mm);
            return min(a,b);
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                vector<int> adj[n+1];
            for(auto x:edges){
                adj[x.first].push_back(x.second);
                adj[x.second].push_back(x.first);
            }
            vector<int> mm(n+1,0);
            int m=edges.size(),count=0,taken=0,v=1;
            return help(count,taken,v,n,m,adj,mm);
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
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends