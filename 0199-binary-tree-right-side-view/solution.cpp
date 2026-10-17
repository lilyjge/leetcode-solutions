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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto e = q.front(); q.pop();
            if (e.second == ans.size()) 
                ans.push_back(e.first->val);
            if (e.first->right != nullptr)
                q.push({e.first->right, e.second + 1});
            if (e.first->left != nullptr)
                q.push({e.first->left, e.second + 1});
        }
        return ans;
    }
};
