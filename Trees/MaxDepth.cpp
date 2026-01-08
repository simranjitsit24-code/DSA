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
    int max(int a , int b)
    {
        return a>b? a:b;
    }
    int maxDepth(TreeNode* root)
     {
        if (!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};