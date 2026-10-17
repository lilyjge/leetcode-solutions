/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> adj[501];
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        vector<int> dis(501, false);
        queue<int> q;
        vector<int> ans;
        q.push(target->val);
        dis[target->val] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if (dis[u] == k)
                ans.push_back(u);
            if (dis[u] > k) return ans;
            for(int v : adj[u]) {
                if (!dis[v] && v != target->val) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return ans;
    }

    void build(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            build(root->left);
        }
        if (root->right != nullptr) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            build(root->right);
        }
    }
};
