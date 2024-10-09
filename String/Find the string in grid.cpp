//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i,int j, int dirx,int diry,int ind,string word,vector<vector<char>>grid){
        if(ind == word.size()){
            return true;
        }
        int xi = i+dirx;
        int yj = j+diry;
        if(xi>=0 && yj>=0 && xi<grid.size() && yj<grid[0].size()){
            if(grid[xi][yj] == word[ind]){
                if(dfs(xi,yj,dirx,diry,ind+1,word,grid)){
                    return true;
                }
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    set<vector<int>>st;
	    
	    int row[] = {1,0,-1,0,1,1,-1,-1};
	    int col[] = {0,1,0,-1,-1,1,1,-1};
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                for(int k=0;k<8;k++){
	                    if(dfs(i,j,row[k],col[k],1,word,grid)){
	                        st.insert({i,j});
	                    }
	                }
	            }
	        }
	    }
	    vector<vector<int>> ans(st.begin(),st.end());
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends