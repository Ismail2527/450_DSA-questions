//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool rec(int sum,int n,vector<int>&vis,int csum,int a[],int k){
        // base case
        if(k==1){
            return 1;
        }
        if(csum>sum){
            return 0;
        }
        if(csum==sum){
            return rec(sum,n,vis,0,a,k-1);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i] =1;
                if(rec(sum,n,vis,csum+a[i],a,k)){
                    return 1;
                }
                vis[i] =0;
                
            }
        }
        return 0;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum =0;
         for(int i=0; i<n; i++){
             sum = sum + a[i];
         }
         if(k>n || sum%k != 0){
             return 0;
         }
         vector<int>vis(n,0);
         sum = sum /k;
         return rec(sum,n,vis,0,a,k);
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends