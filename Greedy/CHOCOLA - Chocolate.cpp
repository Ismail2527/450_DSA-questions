//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        int h=1 , v=1;
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        int ans =0;
        int y = Y.size()-1,x = X.size()-1;
        while(y>=0 && x>=0){
            if(X[x] >= Y[y]){
                ans = ans +(v*X[x]);
                x--;
                h++;
            }else{
                ans = ans +(h*Y[y]);
                y--;
                v++;
            }
        }
        while(y>=0) {
            ans = ans +(h*Y[y]);
            y--;
            v++;
        }
        while(x>=0){
            ans = ans +(v*X[x]);
            x--;
            h++;
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends