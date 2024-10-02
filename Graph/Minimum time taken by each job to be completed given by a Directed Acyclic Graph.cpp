//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here  
            vector<int> inDegree(n + 1, 0);  // to store the in-degree of each node
            vector<vector<int>> adj(n + 1);  // adjacency list

            // Build the graph
            for (int i = 0; i < m; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);
                inDegree[v]++;
            }

            // To store the minimum time for each task
            vector<int> minTime(n + 1, 0);

            // Queue for topological sorting
            queue<int> q;

            // Initialize the queue with nodes having in-degree 0
            for (int i = 1; i <= n; i++) {
                if (inDegree[i] == 0) {
                    q.push(i);
                    minTime[i] = 1;  // Tasks with no dependencies can start at time 1
                }
            }

            // Perform topological sorting
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                // Process all neighbors of the current node
                for (int neighbor : adj[node]) {
                    inDegree[neighbor]--;

                    // Update the minimum time for the neighbor
                    minTime[neighbor] = max(minTime[neighbor], minTime[node] + 1);

                    // If in-degree becomes 0, push it into the queue
                    if (inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            // Return the result, ignoring index 0 (1-based indexing)
            vector<int> result;
            for (int i = 1; i <= n; i++) {
                result.push_back(minTime[i]);
            }
            return result;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends