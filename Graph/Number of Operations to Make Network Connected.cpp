class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int index){
        visited[index] = true;
        for(int i:adj[index]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        vector<vector<int>>adj(n);
        for(auto c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<bool>visited(n,false);
        int comp = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                comp++;
            }
        }
        return comp-1;
    }
};