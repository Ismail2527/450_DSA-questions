#include <bits/stdc++.h> 
void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    int x = row;
    int y = col;

    // Check for the same row
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    // Reset x and y to original positions
    x = row;
    y = col;

    // Check for upper-left diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    // Reset x and y to original positions
    x = row;
    y = col;

    // Check for lower-left diagonal
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    // Base case: All queens are placed
    if (col == n) {
        addSolution(ans, board, n);
        return;
    }

    // Try placing the queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            solve(col + 1, ans, board, n);

            // Backtrack: Remove the queen
            board[row][col] = 0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
	// Write your code here
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
	
}