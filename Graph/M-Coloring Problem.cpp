//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isSafetoAssign(int i, int j, bool graph[101][101], int V, vector<int>& color) {
        for (int k = 0; k < V; k++) {
            if (graph[i][k] == 1 && color[k] == j) {
                return false;  
            }
        }
        return true;
    }

    bool fnc(bool graph[101][101], int m, int V, int i, vector<int>& color) {         
        if (i == V) return true;
        for (int j = 1; j <= m; j++) {  // Iterate over all colors from 1 to m
            if (isSafetoAssign(i, j, graph, V, color)) {
                color[i] = j;
                if (fnc(graph, m, V, i + 1, color)) {
                    return true;  // Coloring is successful
                }
                
                color[i] = -1;  // Backtrack
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int V) {
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