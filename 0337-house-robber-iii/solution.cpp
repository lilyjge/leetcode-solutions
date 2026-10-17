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
    // parent + kid vs self + grandkid
    int rob(TreeNode* root) {
        auto e = recurse(root);
        return max(e.first, e.second);
    }

    // take cur, no take cur
    pair<int, int> recurse(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto left = recurse(root->left);
        auto right = recurse(root->right);
        int take = root->val + left.second + right.second;
        int notake = max(max(max(left.first + right.first, left.first + right.second), left.second + right.first), left.second + right.second);
        cout << root->val << ' ' << take << ' ' << notake << endl;
        return {take, notake};
    }
};
