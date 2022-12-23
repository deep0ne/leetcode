struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;
 
class Solution {
public:

    void traversal(vector<int>& elements, TreeNode* root) {
        if(!root) {
            return;
        }
        elements.push_back(root->val);
        if(root->left) { traversal(elements, root->left); }
        if(root->right) { traversal(elements, root->right); }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> elements;
        traversal(elements, root);
        return elements;
    }
};