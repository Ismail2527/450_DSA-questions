//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int fav=0,Nonfav=0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k){
                fav++;
            }
        }
        for(int j=0; j<fav; j++){
            if(arr[j]>k){
                Nonfav++;
            }
        }
        int l=0,r=fav-1,result = INT_MAX;
        while(r<n)
        {
            result = min(result,Nonfav);
            r++;
            if(r<n && arr[r]>k) Nonfav++;
            if(l<n && arr[l]>k) Nonfav--;
            l++;
        }
        return result;
    }
};



//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends