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
    unordered_map<TreeNode*, int> dp; // max val if we take this node
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dp[root] = root->val;
        if (root->left != nullptr) {
            maxPathSum(root->left);
            dp[root] = max(dp[root], root->val + dp[root->left]);
        }
        if (root->right != nullptr) {
            maxPathSum(root->right);
            dp[root] = max(dp[root], root->val + dp[root->right]);
        }
        ans = max(ans, max(dp[root], root->val + dp[root->left] + dp[root->right]));
        return ans;
    }
};
