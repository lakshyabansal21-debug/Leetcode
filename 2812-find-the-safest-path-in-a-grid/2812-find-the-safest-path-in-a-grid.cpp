#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool isValidPath(vector<vector<int>>& dist, int min_safe) {
        int n = dist.size();
        if (dist[0][0] < min_safe || dist[n-1][n-1] < min_safe) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) return true;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && dist[nr][nc] >= min_safe) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int max_dist = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    max_dist = max(max_dist, dist[nr][nc]);
                    q.push({nr, nc});
                }
            }
        }

        int low = 0, high = max_dist, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValidPath(dist, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};