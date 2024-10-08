//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
     long long ans =0;
     sort(A.begin(),A.end());
     sort(B.begin(),B.end());
     for(int i=0; i<N; i++){
        if(A[i]>B[i]){
            ans = ans + (A[i]-B[i]);
        }
        else {
            ans = ans + (B[i]-A[i]);
        }
     }
     return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        Solution ob;
        cout<<ob.findMinSum(A,B,N)<<endl;
    }
}
// } Driver Code Ends