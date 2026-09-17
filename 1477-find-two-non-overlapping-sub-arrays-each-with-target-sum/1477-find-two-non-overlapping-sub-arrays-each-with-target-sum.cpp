#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;
        
        std::vector<int> min_len(n, INF);
        
        std::unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        
        int current_sum = 0;
        int min_total_sum = INF;
        int best_so_far = INF;

        for (int i = 0; i < n; ++i) {
            current_sum += arr[i];
            prefix_map[current_sum] = i;

            int needed_sum = current_sum - target;
            if (prefix_map.count(needed_sum)) {
                int start_idx = prefix_map[needed_sum];
                int current_len = i - start_idx;

                if (start_idx >= 0 && min_len[start_idx] != INF) {
                    min_total_sum = std::min(min_total_sum, current_len + min_len[start_idx]);
                }

                best_so_far = std::min(best_so_far, current_len);
            }

            min_len[i] = best_so_far;
        }

        return min_total_sum >= INF ? -1 : min_total_sum;
    }
};