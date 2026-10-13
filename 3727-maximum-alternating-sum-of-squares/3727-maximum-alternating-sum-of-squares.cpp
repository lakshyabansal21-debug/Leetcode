#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        
        for (int i = 0; i < n; ++i) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        
        // Sort squares in ascending order
        sort(sq.begin(), sq.end());
        
        long long totalScore = 0;
        int numSubtract = n / 2;
        int numAdd = n - numSubtract;
        
        // Smallest n/2 elements are subtracted
        for (int i = 0; i < numSubtract; ++i) {
            totalScore -= sq[i];
        }
        
        // Largest (n - n/2) elements are added
        for (int i = numSubtract; i < n; ++i) {
            totalScore += sq[i];
        }
        
        return totalScore;
    }
};