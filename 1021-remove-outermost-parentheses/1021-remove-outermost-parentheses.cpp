class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If depth > 0, this '(' is NOT the outermost open parenthesis
                if (depth > 0) {
                    result += c;
                }
                depth++;
            } else {
                depth--;
                // If depth > 0 after decrementing, this ')' is NOT the outermost close parenthesis
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};