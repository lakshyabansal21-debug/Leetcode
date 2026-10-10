class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long maxDiff = 0;
        
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
        }

        // Frequency map of absolute differences
        vector<long long> count(maxDiff + 1, 0);
        for (int i = 0; i < n; i++) {
            count[diff[i]]++;
        }

        long long k = (long long)k1 + k2;

        // Greedy reduction from highest difference to lowest
        for (long long d = maxDiff; d > 0 && k > 0; d--) {
            if (count[d] == 0) continue;

            long long take = min(k, count[d]);
            count[d] -= take;
            count[d - 1] += take;
            k -= take;
        }

        // Calculate final sum of squared differences
        long long ans = 0;
        for (long long d = 1; d <= maxDiff; d++) {
            if (count[d] > 0) {
                ans += count[d] * d * d;
            }
        }

        return ans;
    }
};