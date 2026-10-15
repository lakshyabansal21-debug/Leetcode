class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        
        string ans = "";
        int nines = sum / 9;
        int rem = sum % 9;
        
        for (int i = 0; i < nines; ++i) {
            ans += '9';
        }
        if (rem > 0) {
            ans += to_string(rem);
        }
        while (ans.length() < num) {
            ans += '0';
        }
        
        return ans;
    }
};