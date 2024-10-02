//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    
    vector<long long >Previous_smaller(vector<long long>&heights){
        vector<long long>ans;
        stack<long long>st;
        int n = heights.size();
        
        for(int i=0; i<n; i++){
            while(st.empty() == false && 
            heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ele = (st.empty()) ? -1 : st.top();
            ans.push_back(ele);
            st.push(i);
        }
        return ans;
    }
    vector<long long>Next_smaller(vector<long long>&heights){
        vector<long long>ans;
        stack<long long>st;
        int n = heights.size();
        
        for(int i=n-1; i>=0; i--){
            while(st.empty() == false && 
            heights[st.top()] >= heights[i]){
                st.pop();
            }
            int ele = (st.empty()) ? n : st.top();
            ans.push_back(ele);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long res =0 ;
        vector<long long>h;
        for(int i=0; i<n; i++){
            h.push_back(arr[i]);
        }
        vector<long long>ps = Previous_smaller(h);
        vector<long long>ns = Next_smaller(h);
        for(int i=0; i<n; i++){
            long long curr = (ns[i]-ps[i]-1)*h[i];
            res = max(res,curr);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends