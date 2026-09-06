class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // dp[j] = number of ways to form t[0...j-1]
        // using the characters processed from s
        vector<unsigned long long> dp(m + 1, 0);

        dp[0] = 1;  // Empty string can always be formed

        for (int i = 1; i <= n; i++) {
            // Go backwards so dp[j-1] is still from the previous
            // character of s
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};