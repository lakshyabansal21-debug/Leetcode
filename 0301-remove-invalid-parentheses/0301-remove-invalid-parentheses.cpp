#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int remL = 0, remR = 0;
        
        // Step 1: Calculate the minimum number of '(' and ')' to remove
        for (char c : s) {
            if (c == '(') {
                remL++;
            } else if (c == ')') {
                if (remL > 0) {
                    remL--; // Valid pair matched
                } else {
                    remR++; // Unmatched closing parenthesis
                }
            }
        }
        
        unordered_set<string> resultSet;
        string current = "";
        
        // Step 2: DFS Backtracking with target removal counts
        dfs(s, 0, remL, remR, 0, current, resultSet);
        
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    void dfs(const string& s, int index, int remL, int remR, int openCount, string& current, unordered_set<string>& resultSet) {
        // Early pruning: invalid balance or exceeded allowed removals
        if (remL < 0 || remR < 0 || openCount < 0) return;
        
        // Base case: end of string reached
        if (index == s.length()) {
            if (remL == 0 && remR == 0 && openCount == 0) {
                resultSet.insert(current);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            // Option 1: Remove current '('
            dfs(s, index + 1, remL - 1, remR, openCount, current, resultSet);
            
            // Option 2: Keep current '('
            current.push_back('(');
            dfs(s, index + 1, remL, remR, openCount + 1, current, resultSet);
            current.pop_back();
        } else if (c == ')') {
            // Option 1: Remove current ')'
            dfs(s, index + 1, remL, remR - 1, openCount, current, resultSet);
            
            // Option 2: Keep current ')'
            current.push_back(')');
            dfs(s, index + 1, remL, remR, openCount - 1, current, resultSet);
            current.pop_back();
        } else {
            // Non-parenthesis characters are always kept
            current.push_back(c);
            dfs(s, index + 1, remL, remR, openCount, current, resultSet);
            current.pop_back();
        }
    }
};