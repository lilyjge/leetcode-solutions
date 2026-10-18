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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        recurse(root, true, -1);
        recurse(root, false, -1);
        return ans;
    }

    void recurse(TreeNode* root, bool right, int len) {
        if (root == nullptr) {
            ans = max(ans, len); return;
        }
        if (right) {
            recurse(root->right, !right, len + 1);
            recurse(root->left, right, 0);
        }
        else {
            recurse(root->left, !right, len + 1);
            recurse(root->right, right, 0);
        }
    }
};
