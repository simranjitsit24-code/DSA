#include <iostream>
using namespace std;
class TreeNode {
public:

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sum = 0;
    bool isleaf(TreeNode* root)
    {
        return  root && !root->left && !root->right;
    }
    void left(TreeNode* root)
    {
        if (!root)  return;
        if (root->left && isleaf(root->left)) 
        sum = sum + root->left->val;
        left(root->left);
        left(root->right);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        left(root);
        return sum;
    }
};