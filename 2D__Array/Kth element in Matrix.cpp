//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends




int cnt(int mat[MAX][MAX], int mid,int n) {
        int len = n;
        int count = 0;
        for(int i=0;i<len;i++) {
            if(mat[i][len-1]<mid) {
                count += len;
            }
            else {
                if(mat[i][0]>mid) break;
                int j=0;
                while(mat[i][j]<mid) {
                    j++;
                }
                count += j;
            }
        }
        return count;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
        //int n=m.size();
        int small = mat[0][0];
        int big = mat[n-1][n-1];
        while(small<=big) {
            int mid = small+(big-small)/2;
            if(cnt(mat,mid,n)<k) {
                small = mid+1;
            }
            else {
                big = mid-1;
            }
        }
        return big;
}
