class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        vector<int> right_min(n);
        right_min[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = min(right_min[i + 1], nums[i]);
        }
        
        int left_max = nums[0];
        
        for (int i = 0; i < n; ++i) {
            left_max = max(left_max, nums[i]);
            
            if (left_max - right_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};