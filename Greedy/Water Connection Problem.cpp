class Solution
{
    public:
    void dfs(int src,int s,int mini,int n,unordered_map<int,list<pair<int,int>>>&adj,unordered_map<int,int>&vis,vector<vector<int>>&ans){
        if(src>=1 && src<=n && adj[src].size()==0){
            ans.push_back({s,src,mini});
            return;
        }
        vis[src]=1;
        for(auto &nbh:adj[src]){
            if(!vis[nbh.first]){
                mini=min(mini,nbh.second);
                dfs(nbh.first,s,mini,n,adj,vis,ans);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        unordered_map<int,list<pair<int,int>>>adj;
        unordered_map<int,int>vis;
        unordered_map<int,int>ind;
        adj.clear();
        ind.clear();
        vis.clear();
        
        for(int i=0;i<p;i++){
            adj[a[i]].push_back({b[i],d[i]});
            ind[b[i]]++;
        }
        // for(auto &i:adj){
        //     cout<<i.first<<" ";
        //     for(auto &j:i.second){
        //         cout<<j.first<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            if(ind[i]==0 && adj[i].size()!=0){
                int mini=INT_MAX;
                dfs(i,i,mini,n,adj,vis,ans);
            }
        }
        
        return ans;
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(int node,vector<pair<int,int>>g[],int &mw,int &end,int vis[]){
        vis[node] =1;
        for(auto e:g[node]){
            if(vis[e.first] == 0){
                mw = min(mw,e.second);
                end = e.first;
                dfs(e.first,g,mw,end,vis);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        int vis[n+1];
        vector<vector<int>>ans;
        memset(vis,0,sizeof(vis));
        vector<int>in(n+1,0);
        vector<int>out(n+1,0);
        vector<pair<int,int>>g[n+1];
        for(int i=0; i<p; i++){
            out[a[i]] = 1;
            in[b[i]] = 1;
            g[a[i]].push_back({b[i],d[i]});
        }
        for(int i=1; i<=n; i++){
            if(in[i] == 0 && out[i] == 1 && vis[i] == 0){
                int s=i; 
                int e;
                int mw = INT_MAX;
                dfs(i,g,mw,e,vis);
                ans.push_back({s,e,mw});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends
