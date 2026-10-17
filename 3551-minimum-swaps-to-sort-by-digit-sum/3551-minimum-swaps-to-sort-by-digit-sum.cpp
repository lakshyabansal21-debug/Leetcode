#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    // Helper function to calculate sum of digits
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store pairs of {digit_sum, value} alongside their original indices
        vector<pair<pair<int, int>, int>> mappedNums(n);
        for (int i = 0; i < n; ++i) {
            mappedNums[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        
        // Sort according to custom criteria: primary = digit sum, secondary = value
        sort(mappedNums.begin(), mappedNums.end());
        
        // Cycle detection
        vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // Skip if element is already visited or already in its correct position
            if (visited[i] || mappedNums[i].second == i) {
                continue;
            }
            
            // Find the size of the cycle
            int cycleSize = 0;
            int curr = i;
            
            while (!visited[curr]) {
                visited[curr] = true;
                curr = mappedNums[curr].second; // Jump to the original index
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};