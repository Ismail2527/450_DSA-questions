class Solution {
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
};