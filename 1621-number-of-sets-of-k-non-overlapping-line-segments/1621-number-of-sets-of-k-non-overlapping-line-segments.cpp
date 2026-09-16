class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;
        
        if (r > total || r < 0) return 0;
        
        // Compute binomial coefficient C(total, r) using Pascal's triangle
        vector<vector<long long>> C(total + 1, vector<long long>(r + 1, 0));
        
        for (int i = 0; i <= total; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= min(i, r); ++j) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
        
        return C[total][r];
    }
};