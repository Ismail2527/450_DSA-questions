//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int top=0,bt=matrix.size() -1,right=matrix[0].size()-1,left=0;
        vector<int>ans;
        
        while(left <= right && top <= bt){
            // right
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            // bottom
            for(int i=top; i<=bt; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            //left
            if(top <= bt){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bt][i]);
                }
                bt--;
            }
            if(left <= right){
                for(int i=bt; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends