//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int>st;
      for(int i=0; i<N; i++){
          st.insert(arr[i]);
      }
      int ans = 0 , c=1;
      for(auto it : st){
         if(st.find(it-1) == st.end()){
            int x = it;
            c=1;
            while(st.find(x+1) != st.end()){
                x = x+1;
                c = c + 1;
            }
         }
         ans = max(ans,c);
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends