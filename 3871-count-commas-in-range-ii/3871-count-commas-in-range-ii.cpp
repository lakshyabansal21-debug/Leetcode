class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long threshold = 1000;
        
        // Loop through powers of 1000 up to 10^15
        while (n >= threshold) {
            commas += (n - threshold + 1);
            threshold *= 1000;
        }
        
        return commas;
    }
};