/*Given the root of a binary tree, return the inorder traversal of its nodes' values.*/

#include <vector>
using namespace std;

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
    
    void visit(vector<int>& container, TreeNode* root) {
        if(!root) {return;}
        
        if(root->left) { visit(container, root->left); }
        container.push_back(root->val);
        if(root->right) { visit(container, root->right); }
        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        visit(ans, root);
        return ans;
    }
        
};