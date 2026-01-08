#include<bits/stdc++.h>
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
    int min(int a,int b)
    {
        return a<b? a:b;
    }
    int minDepth(TreeNode* root) 
    {
        if (!root) return 0;
        if (!root->left && !root->right)
            return 1;

        if (!root->left)
            return minDepth(root->right) + 1;

        if (!root->right)
            return minDepth(root->left) + 1;
            
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};