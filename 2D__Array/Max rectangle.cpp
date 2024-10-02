//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int> ns(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> pv(vector<int> &arr, int n)
    {
        // Write your code here.
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        next = ns(heights,n);
        vector<int>prev(n);
        prev = pv(heights,n);
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] -prev[i]-1;
            int lar = b*l;
            ans = max(lar,ans);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>temp(m,0);
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] == 1){
                    temp[j]++;
                }
                else{
                    temp[j]=0;
                }
            }
            int pre = largestRectangleArea(temp);
            ans = max(ans,pre);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends