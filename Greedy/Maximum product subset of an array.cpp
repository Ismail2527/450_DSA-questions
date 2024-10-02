//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        if(arr.size() == 1){
            return arr[0];
        }
        // find Ncount and MaxN
        long long int ans =1;
        int Ncount =0;
        int MaxN =INT_MIN;
        int zerocheck = 0;
        int z = 0, minOne = 0;
        // check all or 0
        
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<0){
                minOne++;
            }
            if(arr[i] == 0){
                zerocheck++;
            }
            if(arr[i]<0 && arr[i] != 0){
                Ncount++;
                if(MaxN<arr[i]){
                    MaxN = arr[i];
                }
            }
        }
        long long int mod =  1e9+7;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > 0){
                ans = ans * arr[i]%mod;
            }else if(arr[i]<0 && Ncount%2 != 0){
                if(arr[i] == MaxN){
                    
                    MaxN = INT_MIN;
                }else{
                    ans = ans * arr[i]%mod;   
                }
            }else if(arr[i]<0 && Ncount%2 == 0){
                ans = ans * arr[i]%mod;
            }
        }
        if(minOne == 1 && zerocheck == arr.size()-1){
            return 0;
        }
        if(zerocheck==1 && minOne==1 && (zerocheck+minOne == arr.size())){
            return 0;
        }
        if(zerocheck == arr.size()){
            return 0;
        }else{
            return ans%mod;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends