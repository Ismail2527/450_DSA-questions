//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  int minSwapsToSort(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int,int>>v(n);
	    for(int i=0; i<n; i++){
	        v[i] = {nums[i],i};
	    }
	    sort(v.begin(),v.end());
	    int c=0;
	    for(int i=0; i<n; i++){
	        if(v[i].second == i){
	            continue;
	        }
	        else{
	            c++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return c;
	}

// Helper function to perform inorder traversal
void inorderTraversal(vector<int>& A, vector<int>& inorder, int index) {
    if (index >= A.size()) {
        return;
    }
    inorderTraversal(A, inorder, 2 * index + 1); // Left child
    inorder.push_back(A[index]);
    inorderTraversal(A, inorder, 2 * index + 2); // Right child
}
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> inorder;
        inorderTraversal(A, inorder, 0);
        return minSwapsToSort(inorder);
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends