//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void findCombinations(int index, vector<int>& A,
    int target, vector<int>& current, 
    vector<vector<int>>& result) {
        // Base case: If target is 0, we have found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Explore further by choosing each candidate in A starting from the current index
        for (int i = index; i < A.size(); i++) {
            if (A[i] > target) break; // No need to proceed if the current number is greater than the target

            // Choose the number
            current.push_back(A[i]);
            // Recur with the updated target and allow the same index (i) to be chosen again
            findCombinations(i, A, target - A[i], current, result);
            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(), A.end());
        // Remove duplicates
        A.erase(unique(A.begin(), A.end()), A.end());

        vector<vector<int>> result;
        vector<int> current;

        // Start the combination finding process
        findCombinations(0, A, B, current, result);
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends