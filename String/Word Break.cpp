//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
 
// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    bool solve(string s, unordered_map<string, int>& mp) {
        int size = s.size();
        if (size == 0) return true;

        for (int i = 1; i <= size; i++) {
            string prefix = s.substr(0, i);

            if (mp[prefix] && solve(s.substr(i), mp)) {
                return true;
            }
        }
        return false;
    }

    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_map<string,int>mp;
        string empty = "";
        for(int i=0; i<dictionary.size(); i++){
            mp[dictionary[i]]++;
        }
        return solve(s,mp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends