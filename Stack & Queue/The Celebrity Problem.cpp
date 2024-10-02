//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    bool knows(int a,int b,vector<vector<int>>&M,int n){
        if(M[a][b] == 1){
            return true;
        }else{
            return false;
        }
    }
    int celebrity(vector<vector<int> >& M) {
        // code here
        
        int n = M.size();
        if (n == 1) {
            return M[0][0] == 0 ? 0 : -1;
        }

        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Reduce the potential celebrities to one candidate
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (knows(a, b, M, n)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        int ans = s.top();
        s.pop();

        // Check if this candidate is actually a celebrity
        int rowCount = 0;
        int colCount = 0;

        // Row check: candidate should not know anyone else
        for (int i = 0; i < n; i++) {
            if (M[ans][i] == 0) {
                rowCount++;
            }
        }

        // Column check: everyone else should know the candidate
        for (int i = 0; i < n; i++) {
            if (M[i][ans] == 1) {
                colCount++;
            }
        }

        // The celebrity condition
        if (rowCount == n && colCount == n - 1) {
            return ans;
        } else {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends