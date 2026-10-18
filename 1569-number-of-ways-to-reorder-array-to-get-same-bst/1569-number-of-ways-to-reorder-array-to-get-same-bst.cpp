#include <vector>

using namespace std;

class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
    vector<vector<long long>> table;

    // Precompute Pascal's triangle for combination values C(n, k)
    void precomputeCombinations(int n) {
        table.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            table[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        int m = nums.size();
        if (m <= 2) return 1;

        vector<int> leftNums, rightNums;
        int root = nums[0];

        for (int i = 1; i < m; ++i) {
            if (nums[i] < root) {
                leftNums.push_back(nums[i]);
            } else {
                rightNums.push_back(nums[i]);
            }
        }

        long long leftWays = dfs(leftNums) % MOD;
        long long rightWays = dfs(rightNums) % MOD;

        int leftLen = leftNums.size();
        int rightLen = rightNums.size();

        // C(leftLen + rightLen, leftLen) * leftWays * rightWays
        long long totalWays = (table[leftLen + rightLen][leftLen] * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeCombinations(n);
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};