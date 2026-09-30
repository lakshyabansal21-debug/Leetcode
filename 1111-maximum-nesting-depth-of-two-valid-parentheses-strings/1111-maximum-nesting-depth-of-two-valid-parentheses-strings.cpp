class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d = 0;
        for (char c : seq) {
            if (c == '(') {
                ans.push_back(d % 2);
                d++;
            } else {
                d--;
                ans.push_back(d % 2);
            }
        }
        return ans;
    }
};
