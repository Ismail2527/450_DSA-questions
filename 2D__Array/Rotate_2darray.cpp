#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(int n, int m, vector<vector<int>>& mat) {
    // Create an answer matrix initialized to 0
    vector<vector<int>> ans(n, vector<int>(m));
    
    // Loop through each row in reverse order
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            ans[n - 1 - i][j] = mat[i][j]; // Fill the result by reversing rows
        }
    }
    
    return ans; // Return the result matrix
}

int main() {
    int n, m;
    cin >> n >> m; // Input dimensions
    vector<vector<int>> mat(n, vector<int>(m)); // Initialize input matrix
    
    // Input matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    // Rotate the matrix
    vector<vector<int>> result = rotate(n, m, mat);
    
    // Display the rotated matrix
    for (const auto& row : result) {
        for (const auto& elem : row) {
            cout << elem << " "; // Print each element
        }
        cout << endl; // New line after each row
    }

    return 0;
}
