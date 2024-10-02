#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&arr,int n,int m){
    unordered_map<int,int>mp;
    for(int i=0; i<m; i++){
        mp[arr[0][i]]=1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(mp[arr[i][j]] == i){
                mp[arr[i][j]] = i+1;
                if(i==n-1 && mp[arr[i][j]] == n){
                    cout<<"  "<<arr[i][j]<<" "<<endl;
                }
            }
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter row then colom"<<endl;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    solve(arr,n,m);
    return 0;
}