//User function Template for C++

class Solution{
    public:
    int selectKcities(int n, int k, vector<vector<int>>& mat){
        //code here
        // Initialize variables to store the minimum of the maximum distances.
        int minMaxDistance = INT_MAX;

        // Generate all possible combinations of K cities out of N cities.
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        vector<bool> selected(n, false);
        fill(selected.begin(), selected.begin() + k, true);
        
        do {
            // For each combination, calculate the maximum distance of any city from the nearest server.
            int maxDist = 0;
            for (int i = 0; i < n; i++) {
                int nearestDist = INT_MAX;
                for (int j = 0; j < n; j++) {
                    if (selected[j]) {
                        nearestDist = min(nearestDist, mat[i][j]);
                    }
                }
                maxDist = max(maxDist, nearestDist);
            }
            minMaxDistance = min(minMaxDistance, maxDist);
        } while (prev_permutation(selected.begin(), selected.end()));
        
        return minMaxDistance;
    }
};
