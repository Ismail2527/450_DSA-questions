//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
        vector<vector<int>> lcs(n+1, vector<int>(n+1, 0)); // Table of size (n+1) x (n+1)

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i-1] == str[j-1] && i != j) { // Ensure indices are different
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }

        return lcs[n][n]; // The result is stored at lcs[n][n]
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends