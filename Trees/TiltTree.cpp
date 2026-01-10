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
    int sum = 0;
    int abs(int b)
    {
        return b>0? b:-b;
    }
    int find(TreeNode* root) {

         
        if (!root) return 0;
        int l = find(root->left);
        int r = find(root->right);
        sum = sum + abs(l-r);
        return root->val + l+r;
    }
    int findTilt(TreeNode* root)
    {
        find (root);
        return sum;
    }
};