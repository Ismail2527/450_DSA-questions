class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adj list;
        /*vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }*/
        unordered_map<int, list<pair<int, int>>> adj;
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});  // Directed graph, only one direction
        }
        queue<pair<int,pair<int,int>>>q;
        //{stops,{node,distace}}
        q.push({0,{src,0}});
        vector<int>dest(n,INT_MAX);
        dest[src] = 0;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int stops = top.first;
            int node = top.second.first;
            int dist = top.second.second;
            if(stops > k) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int we = it.second;

                if(we+dist < dest[adjnode] && stops <= k){
                    dest[adjnode] = we + dist;
                    q.push({stops+1,{adjnode,dest[adjnode]}});
                }
            }
        }
        if(dest[dst] == INT_MAX){
            return -1;
        }
        return dest[dst];
    }
};