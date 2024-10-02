class Solution {
public:
    bool IsSafe(vector<vector<int>>& image, int i, 
    int j,int n,int m,int ncolor){
        if(i>=0 && j>=0 && i<n && j<m && 
        image[i][j] == ncolor){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>& image, int i, int j, 
    int color,int n,int m,int ncolor){
        image[i][j] = color;
        if(IsSafe(image,i+1,j,n,m,ncolor)){
            solve(image,i+1,j,color,n,m,ncolor);
        }
        if(IsSafe(image,i-1,j,n,m,ncolor)){
            solve(image,i-1,j,color,n,m,ncolor);
        }
        if(IsSafe(image,i,j+1,n,m,ncolor)){
            solve(image,i,j+1,color,n,m,ncolor);
        }
        if(IsSafe(image,i,j-1,n,m,ncolor)){
            solve(image,i,j-1,color,n,m,ncolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int ncolor = image[sr][sc];
        if(ncolor == color){
            returvn image;
        }
        solve(image,sr,sc,color,n,m,ncolor);
        return image;
    }
};