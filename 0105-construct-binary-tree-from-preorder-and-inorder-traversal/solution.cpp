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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        // construct left child, right child
        vector<int> preleft, inleft;
        int i = 0;
        while(inorder[i] != root->val) {
            preleft.push_back(preorder[i+1]);
            inleft.push_back(inorder[i]);
            i++;
        }
        root->left = buildTree(preleft, inleft);
        vector<int> preright, inright;
        i++;
        while (i < preorder.size()) {
            preright.push_back(preorder[i]);
            inright.push_back(inorder[i]);
            i++;
        }
        root->right = buildTree(preright, inright);
        return root;
    }
};
