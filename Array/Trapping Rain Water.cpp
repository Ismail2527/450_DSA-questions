//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    long long trappingWater(vector<int> &arr) {
        // code here
        long long n = arr.size();
        vector<long long>lmax(n);
        //left max array;
        lmax[0] = arr[0];
        for(long long i=1; i<n; i++){
            lmax[i] = max(lmax[i - 1], static_cast<long long>(arr[i]));
        }
        //right max array
        vector<long long>Rmax(n);
        Rmax[n-1] = arr[n-1];
        for(long long i=n-2; i>=0; i--){
            Rmax[i] = max(Rmax[i + 1], static_cast<long long>(arr[i]));
        }
        long long water=0;
        for(long long i=1; i<n-1; i++){
            water += min(lmax[i],Rmax[i])-arr[i];
        }
        return water;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;

        vector<int> a(n);

        // adding elements to the array
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a) << endl;
    }

    return 0;
}
// } Driver Code Ends