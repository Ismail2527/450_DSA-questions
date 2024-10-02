//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string s, vector<string>& ans, int index) {
        // Base case: If we've reached the end of the string, add it to the results
        if (index >= s.length()) {
            ans.push_back(s);
            return;
        }
        
        // Recursively swap each character with the current index
        for (int j = index; j < s.length(); j++) {
            swap(s[index], s[j]);
            solve(s, ans, index + 1);
            // Backtrack
            swap(s[index], s[j]);
        }
    }
    
	    vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
            solve(S, ans, 0);
        
            // Remove duplicates and sort
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
            return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends