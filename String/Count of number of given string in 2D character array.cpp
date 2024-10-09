#include <iostream>
#include <vector>
using namespace std;

int rows, cols;

// Directions arrays for moving in 8 directions (up, down, left, right, and 4 diagonals)
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Recursive function to count the occurrences of the string starting from (x, y)
int countOccurrences(vector<vector<char>>& grid, string& word, int x, int y, int index) {
    // Base case: if the entire word is matched
    if (index == word.size()) return 1;

    // Boundary checks and character match check
    if (x < 0 || y < 0 || x >= rows || y >= cols || grid[x][y] != word[index]) return 0;

    int count = 0;

    // Explore in all 8 possible directions
    for (int dir = 0; dir < 8; dir++) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        count += countOccurrences(grid, word, newX, newY, index + 1);
    }

    return count;
}

// Function to count the total occurrences of the word in the grid
int findStringInGrid(vector<vector<char>>& grid, string word) {
    rows = grid.size();
    cols = grid[0].size();
    int totalOccurrences = 0;

    // Try starting the word from every cell in the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            totalOccurrences += countOccurrences(grid, word, i, j, 0);
        }
    }

    return totalOccurrences;
}

int main() {
    vector<vector<char>> grid = {
        {'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a'}
    };

    string word = "aba";

    int result = findStringInGrid(grid, word);
    cout << "Total occurrences of the word: " << result << endl;

    return 0;
}
