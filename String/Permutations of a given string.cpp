//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string s,set<string>&ans,int index){
	        int n = s.size();
            //base case
            if(index >= n){
                ans.insert(s);
                return;
            }
            for(int i=index; i<n; i++){
                swap(s[i],s[index]);
                solve(s,ans,index+1);
                swap(s[i],s[index]);
            }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>ans;
		    solve(S,ans,0);
		    vector<string>res (ans.begin(),ans.end());
		    return res;
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