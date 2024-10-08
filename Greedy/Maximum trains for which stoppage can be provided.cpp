//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
  static bool comp(vector<int>&a, vector<int>&b){
      if(a[1] == b[1]){
          return a[3] < b[3];
      }
      return a[1] < b[1];
  }
    int maxStop(int n, int m, vector<vector<int>> &trains) {
        // code here
        for(int i=0; i<m; i++){
            
            trains[i].push_back(i);
        }
        
        sort(trains.begin(),trains.end(),comp);
        
        vector<int>palt(n+1,-1);
        int ans =0;
        for(int i=0; i<m; i++){
            int at = trains[i][0];
            int dt = trains[i][1];
            int pt = trains[i][2];
            
            if(palt[pt] <= at){
                ans++;
                palt[pt] = dt;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> trains(m, vector<int>(3));
        Matrix::input(trains,m,3);
        
        Solution obj;
        int res = obj.maxStop(n, m, trains);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends