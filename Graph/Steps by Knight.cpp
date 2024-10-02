//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isValid(int i,int j,int n,vector<vector<bool>>&vis){
	    if(i>=0 && j>=0 && i<n && j<n && vis[i][j] == false){
	        return true;
	    }
	    return false;
	}
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int tx = TargetPos[0]-1,ty=TargetPos[1]-1;
	    int px = KnightPos[0]-1,py=KnightPos[1]-1;
	    queue<pair<int,int>>q;
	    if(tx == px && ty == py) return 0;
	    vector<vector<bool>>vis(n,vector<bool>(n,false));
	    q.push({px,py});
	    vis[px][py] = true;
	    
	    int ans =0;
	    while(!q.empty()){
	        int size = q.size();
	        ans++;
	        while(size != 0){
	            pair<int,int>p = q.front();
	            q.pop();
	            int xx=p.first;
	            int yy=p.second;
	            int ax[8] = {-1 ,-1, 1,1,-2, 2,-2,2};
	            int ay[8] = {-2  ,2,-2,2,-1,-1, 1,1};
	            for(int i=0; i<8; i++){
	                int nx = ax[i] + xx;
	                int ny = ay[i] + yy;
	                
	                if(nx == tx && ny == ty) return ans;
	                
	                if(isValid(nx,ny,n,vis)){
	                    vis[nx][ny] = true;
	                    q.push({nx,ny});
	                }
	            }
	            size--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends