// Given the root of a binary tree, determine if it is a valid binary search tree (BST).


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:

    bool validate(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) { return true; }
        if( (min && root->val <= min->val) || (max && root->val >= max->val)) {
            return false;
        }
        return validate(root->left, min, root) && validate(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};