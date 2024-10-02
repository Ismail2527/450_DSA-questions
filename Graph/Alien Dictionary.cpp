//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
    void dfs(string &ans,vector<int>&vis,
    vector<vector<int>>&v,int &i){
        vis[i] = 1;
        for(auto x:v[i]){
            if(!vis[x]){
                dfs(ans,vis,v,x);
            }
        }
        char ch = i + 'a';
        ans = ch + ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<vector<int>>v(k);
        for(int i=0; i<n-1; i++){
            string  st1 = dict[i];
            string  st2 = dict[i+1];
            for(int j=0; j<min(st1.length(),st2.length()); j++){
                if(st1[j] != st2[j]){
                    v[st1[j]-'a'].push_back(st2[j]-'a');
                    break;
                }
            }
        }
        vector<int>vis(k,0);
        string ans = "";
        for(int i=0; i<k; i++){
            if(!vis[i]){
                dfs(ans,vis,v,i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends