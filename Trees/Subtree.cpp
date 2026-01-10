#include <bits/stdc++.h>
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
    bool same(TreeNode* root,TreeNode* subRoot)
    {
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;
        return same(root->left,subRoot->left) && same(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
       if(!root) return false;
       if (same(root,subRoot)) return true;
       return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};