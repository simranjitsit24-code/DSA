#include <iostream>
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
    bool eval(TreeNode* root)
    {
        if (!root) return true;
        if (!root->left && !root->right) 
        {
            if (root->val == 1) return true;
            else return false;
        }
        if (root->val==2)
        {
        return eval(root->left)||eval(root->right);
        }
        if (root->val==3)
        {
        return eval(root->left)&&eval(root->right);
        }
        return false;
    }
    bool evaluateTree(TreeNode* root) {
        return eval(root);
    }
};