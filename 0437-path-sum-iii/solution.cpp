typedef long long ll;
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
    // 
    int target; int ans = 0;
    TreeNode* r;
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum; r = root;
        unordered_map<ll, int> m;
        m[target] = 1;
        recurse(root, m);
        return ans;
    }

    void recurse(TreeNode* root, unordered_map<ll, int>& mp) {
        if (root == nullptr) return;
        if (mp.find(root->val) != mp.end())
            ans += mp[root->val];
        unordered_map<ll, int> nmp;
        for (auto e : mp) { // all ancestors
            nmp[e.first - root->val] = e.second;
        }
        nmp[target]++;
        // if (r != root)
        //     nmp[target - root->val]++;
        recurse(root->left, nmp);
        recurse(root->right, nmp);
    }
};
