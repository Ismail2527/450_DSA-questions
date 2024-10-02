class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxi = max(maxi, width * height);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        vector<int> histo(matrix[0].size(),0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<histo.size(); j++){
                if(matrix[i][j] == '1'){
                    histo[j]++;
                }
                else{
                    histo[j] =0;
                }
            }
            maxi = max(maxi,largestRectangleArea(histo));
        }
        return maxi;
    }
};