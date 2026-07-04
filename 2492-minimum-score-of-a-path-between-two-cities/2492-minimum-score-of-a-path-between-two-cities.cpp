class Solution {
private:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& visited, int& min_road) {
        visited[node] = 1;
        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int distance = edge.second;
            min_road = min(min_road, distance);
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, min_road);
            }
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<int> visited(n + 1, 0);
        int min_road = INT_MAX;
        
        dfs(1, adj, visited, min_road);
        
        return min_road;
    }
};