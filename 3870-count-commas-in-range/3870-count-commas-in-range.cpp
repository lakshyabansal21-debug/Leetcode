class Solution {
public:
    int countCommas(int n) {
        // If n < 1000, it returns 0.
        // If n >= 1000, it returns n - 999.
        return max(0, n - 999);
    }
};