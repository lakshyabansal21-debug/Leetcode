#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
    struct Result {
        long long weight = 0;
        vector<int> selected;
        
        bool operator<(const Result& other) const {
            if (weight != other.weight)
                return weight < other.weight;
            return selected > other.selected; 
        }
    };

    using Interval = tuple<int, int, int, int>;

    Result dp(const vector<Interval>& intervals, vector<vector<Result>>& memo, int i, int quota) {
        if (i == intervals.size() || quota == 0)
            return {0, {}};
        if (memo[i][quota].weight != -1 || !memo[i][quota].selected.empty())
            return memo[i][quota];

        Result skip = dp(intervals, memo, i + 1, quota);

        auto [l, r, weight, originalIndex] = intervals[i];
        
        int j = findFirstGreater(intervals, i + 1, r);
        Result nextRes = dp(intervals, memo, j, quota - 1);

        vector<int> newSelected = nextRes.selected;
        newSelected.push_back(originalIndex);
        sort(newSelected.begin(), newSelected.end());

        Result pick = {weight + nextRes.weight, newSelected};

        if (pick.weight > skip.weight || (pick.weight == skip.weight && pick.selected < skip.selected)) {
            return memo[i][quota] = pick;
        }
        return memo[i][quota] = skip;
    }

    int findFirstGreater(const vector<Interval>& intervals, int startFrom, int rightBoundary) {
        int l = startFrom, r = intervals.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (get<0>(intervals[m]) > rightBoundary) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& input) {
        int n = input.size();
        vector<Interval> intervals;
        for (int i = 0; i < n; ++i) {
            intervals.emplace_back(input[i][0], input[i][1], input[i][2], i);
        }
        
        sort(intervals.begin(), intervals.end());

        vector<vector<Result>> memo(n, vector<Result>(5, {-1, {}}));

        return dp(intervals, memo, 0, 4).selected;
    }
};