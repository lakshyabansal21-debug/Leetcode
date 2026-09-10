/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int matchingNodes = 0;
        dfs(root, matchingNodes);
        return matchingNodes;
    }

private:
    std::pair<int, int> dfs(TreeNode* node, int& matchingNodes) {
        if (!node) return {0, 0}; // returns {subtree_sum, node_count}

        auto [leftSum, leftCount] = dfs(node->left, matchingNodes);
        auto [rightSum, rightCount] = dfs(node->right, matchingNodes);

        int totalSum = node->val + leftSum + rightSum;
        int totalCount = 1 + leftCount + rightCount;

        // C++ integer division automatically truncates (floors) toward zero
        if (node->val == totalSum / totalCount) {
            matchingNodes++;
        }

        return {totalSum, totalCount};
    }
};