//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    // Sorting the array in non-increasing order
	    sort(arr, arr + n, greater<int>());
	    
	    // Vector to store the k largest elements
	    vector<int> ans;
	    
	    // Collect the first k elements from the sorted array
	    for(int i = 0; i < k; i++) {
	        ans.push_back(arr[i]);
	    }
	    
	    return ans;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends