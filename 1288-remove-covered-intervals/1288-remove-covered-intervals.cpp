#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int removedCount = 0;
        int maxEnd = -1;
        
        for (const auto& interval : intervals) {
            if (interval[1] <= maxEnd) {
                removedCount++;
            } else {
                maxEnd = interval[1];
            }
        }
        
        return intervals.size() - removedCount;
    }
};