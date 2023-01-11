/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

    The left
    subtree
    of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>

using namespace std;

class Solution {
public:

    bool isValidBST(TreeNode* root) {
        TreeNode* tmp = nullptr;
        stack<TreeNode*> nodes_stack_;
        while(!nodes_stack_.empty() || root != nullptr) {
            while(root != nullptr) {
                nodes_stack_.push(root);
                root = root->left;
            }
            root = nodes_stack_.top();
            nodes_stack_.pop();
            if(tmp != nullptr && tmp->val >= root->val) {
                return false;
            }
            tmp = root;
            root = root->right;
        }
        return true;
    }
};