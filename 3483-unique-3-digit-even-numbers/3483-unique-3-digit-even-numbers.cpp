class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }
        
        int result = 0;
        
        // Step by 2 to check ONLY even numbers (100, 102, 104, ... 998)
        for (int i = 100; i <= 998; i += 2) {
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int units = i % 10;
            
            count[hundreds]--;
            count[tens]--;
            count[units]--;
            
            if (count[hundreds] >= 0 && count[tens] >= 0 && count[units] >= 0) {
                result++;
            }
            
            count[hundreds]++;
            count[tens]++;
            count[units]++;
        }
        
        return result;
    }
};