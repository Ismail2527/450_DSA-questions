//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>p;
        for(int i=0; i<n; i++){
            p.push_back({price[i],i+1});
        }
        sort(p.begin(),p.end());
        int ans=0;
        for(int i=0; i<n; i++){
            int price=p[i].first;
            int price2 = p[i].second;
            int mul = price*price2;
            if(mul<=k){
                k = k-mul;
                ans = ans + price2;
            }else{
                ans = ans + (k/price);
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends