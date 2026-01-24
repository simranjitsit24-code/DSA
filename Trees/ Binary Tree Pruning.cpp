#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool one(TreeNode* root)
    {
        if (!root) return false;
        if (root->val == 1) return true;
        return one(root->left) || one (root->right);
    }
    void check(TreeNode* &root)
    {
        if (!root) return;
        if (root->left && !one(root->left) )  root->left =  nullptr;
        if (root->right && !one(root->right) )  root->right = nullptr;
        check(root->left);
        check(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
       check (root);
       if (root->val==0 && !root->left && !root->right) return nullptr;
       return root;
    }
};