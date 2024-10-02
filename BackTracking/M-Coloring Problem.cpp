//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafetoAssign(int i, int j, bool graph[101][101], int V, vector<int>& color) {
        // Checking if I can assign color j to node i
        // No other neighboring node of i should have the same color
        for (int k = 0; k < V; k++) {
            if (graph[i][k] == 1 && color[k] == j) {
                return false;  // Neighbor has the same color
            }
        }
        return true;  // Safe to assign color j to node i
    }

    bool fnc(bool graph[101][101], int m, int V, int i, vector<int>& color) {         
        if (i == V) return true;  // All nodes are colored successfully
        
        for (int j = 1; j <= m; j++) {  // Iterate over all colors from 1 to m
            if (isSafetoAssign(i, j, graph, V, color)) {
                color[i] = j;  // Assign color j to node i
                
                // Recur to assign colors to the rest of the nodes
                if (fnc(graph, m, V, i + 1, color)) {
                    return true;  // Coloring is successful
                }
                
                color[i] = -1;  // Backtrack
            }
        }
        
        return false;  // No valid coloring found
    }
    bool graphColoring(bool graph[101][101], int m, int V) {
        // your code here
        //true or false
        vector<int>color(V,-1);
        return fnc(graph,m,V,0,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends