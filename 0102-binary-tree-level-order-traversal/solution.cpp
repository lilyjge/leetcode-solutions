typedef pair<TreeNode*, int> pi;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pi> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.first == nullptr) continue;
            TreeNode* r = cur.first;
            int i = cur.second;
            if (i >= ans.size()) ans.push_back({});
            ans[i].push_back(r->val);
            q.push({r->left, i + 1});
            q.push({r->right, i + 1});
        }
        return ans;
    }
};
