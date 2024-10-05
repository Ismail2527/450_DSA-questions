//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        //Write your code here
        int n = str.size();
        int z = 0, one = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            if(str[i] == '0'){
                z++;
            } else {
                one++;
            }
            
            // When the count of '0's and '1's is equal, increase the answer count
            if(z == one){
                ans++;
            }
        }
        
        // If no valid substring was found, return -1
        if(z != one){
            return -1;
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
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends