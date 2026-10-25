#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid) {
        // Out of bounds or water cell, return
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark current land as visited/water
        grid[r][c] = 1;
        
        // Traverse all 4 directions
        dfs(r + 1, c, rows, cols, grid);
        dfs(r - 1, c, rows, cols, grid);
        dfs(r, c + 1, rows, cols, grid);
        dfs(r, c - 1, rows, cols, grid);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Eliminate all land cells connected to the borders
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && grid[i][j] == 0) {
                    dfs(i, j, rows, cols, grid);
                }
            }
        }
        
        // Step 2: Count remaining closed islands
        int closedIslandsCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    closedIslandsCount++;
                    dfs(i, j, rows, cols, grid); // Sink this entire closed island
                }
            }
        }
        
        return closedIslandsCount;
    }
};