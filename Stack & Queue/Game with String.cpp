//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minValue(string s, int k) {
        // code here
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        priority_queue<int>pq;
        for(auto x : mp){
            pq.push(x.second);
        }
        while(k != 0){
            int x = pq.top();
            pq.pop();
            x--;
            pq.push(x);
            k--;
        }
        int sum =0;
        while(!pq.empty()){
            int top = pq.top();
            sum = sum + (top * top);
            pq.pop();
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends