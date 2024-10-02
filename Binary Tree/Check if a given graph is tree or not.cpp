//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        if (m != n - 1) {
            return 0;
        }
        // Create an adjacency list to represent the graph.
        vector<vector<int>> adj(n);
        // Build the adjacency list from the given edges.
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // Initialize variables for BFS.
        int cnt = 1; // Number of nodes visited
        int st = 0; // Starting node
        vector<bool> vis(n, false); // Visited array
        queue<int> q; // Queue for BFS
        vis[st] = true; // Mark the starting node as visited
        q.push(st); // Add the starting node to the queue
        // Perform BFS to traverse the graph.
        while (!q.empty()) {
            int curr = q.front(); // Get the current node
            q.pop(); // Remove the current node from the queue
            // Iterate over the neighbors of the current node.
            for (int nei : adj[curr]) {
                // If the neighbor is not visited, mark it visited and add it to the queue.
                if (!vis[nei]) {
                    vis[nei] = 1;
                    cnt++; // Increment the count of visited nodes
                    q.push(nei); // Add the neighbor to the queue
                }
            }
        }
        // If all nodes have been visited, the graph is a tree.
        return cnt == n; 
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends