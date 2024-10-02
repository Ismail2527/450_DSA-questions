class Solution {
public:
    // Fix function name and logic
    vector<int> findCoordinate(int curr, int n) {
        int row = n - (curr - 1) / n - 1;
        int col = (curr - 1) % n;
        vector<int> ans(2);
        // Fix logic for column calculation
        if (row % 2 == n % 2) {
            ans[0] = row;
            ans[1] = n - 1 - col; // Corrected 'c' to 'col'
        } else {
            ans[0] = row;
            ans[1] = col;
        }
        return ans;
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int ans = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false)); // Initialize with 'bool'
        q.push(1);
        vis[n-1][0] = true;

        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int x = q.front();
                q.pop();
                
                if (x == n * n) return ans; // Reached the end, return answer

                for (int j = 1; j <= 6; j++) {
                    if (x + j > n * n) break; // No need to process further
                    vector<int> pos = findCoordinate(x + j, n);
                    int f = pos[0];
                    int s = pos[1];

                    if (vis[f][s]) continue; // Skip if already visited
                    vis[f][s] = true;

                    if (board[f][s] == -1) {
                        q.push(x + j); // Push the normal cell
                    } else {
                        q.push(board[f][s]); // Push the destination from the ladder/snake
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};