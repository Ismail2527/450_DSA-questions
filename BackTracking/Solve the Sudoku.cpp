//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    // Function to check if placing a value is safe.
    bool isSafe(int row, int col, int grid[N][N], int val) {
        for (int i = 0; i < N; i++) {
            // Check row
            if (grid[row][i] == val) {
                return false;
            }
            // Check column
            if (grid[i][col] == val) {
                return false;
            }
            // Check 3x3 subgrid
            if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to solve the Sudoku
    bool solve(int grid[N][N]) {
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                // Check if the cell is empty
                if (grid[row][col] == UNASSIGNED) {
                    for (int val = 1; val <= 9; val++) {
                        // Check if placing val is safe
                        if (isSafe(row, col, grid, val)) {
                            grid[row][col] = val;

                            // Recursively solve the rest of the board
                            if (solve(grid)) {
                                return true;
                            } else {
                                // Backtrack if the solution is not valid
                                grid[row][col] = UNASSIGNED;
                            }
                        }
                    }
                    // Return false if no valid number can be placed
                    return false;
                }
            }
        }
        // Return true when all cells are filled correctly
        return true;
    }

    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << " ";
            }
              // Print each row on a new line
        }
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends