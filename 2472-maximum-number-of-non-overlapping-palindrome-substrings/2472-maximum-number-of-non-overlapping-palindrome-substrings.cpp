class Solution {
public:
    int maxPalindromes(string s, int k) {
        const int n = s.length();
        // dp[i] := the maximum number of palindromic substrings in the first i characters of s
        vector<int> dp(n + 1, 0);

        for (int i = k; i <= n; ++i) {
            // Carry forward the max palindromes from the previous index
            dp[i] = dp[i - 1];

            // Check for a palindrome of length k ending at index i - 1
            if (isPalindrome(s, i - k, i - 1)) {
                dp[i] = max(dp[i], 1 + dp[i - k]);
            }

            // Check for a palindrome of length k + 1 ending at index i - 1
            if (isPalindrome(s, i - k - 1, i - 1)) {
                dp[i] = max(dp[i], 1 + dp[i - k - 1]);
            }
        }

        return dp[n];
    }

private:
    // Helper function to check if s[l...r] is a palindrome
    bool isPalindrome(const string& s, int l, int r) {
        if (l < 0) return false;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};