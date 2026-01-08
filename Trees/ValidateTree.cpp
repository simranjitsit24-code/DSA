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
    vector<TreeNode*> res;
    void inorder(TreeNode* root)
    {
     if (!root) return;
     inorder(root->left);
     res.push_back(root);
     inorder(root->right);
 }
    bool isValidBST(TreeNode* root) {
       inorder(root);
       for (int i=1;i<res.size();i++)
       {
        if (res[i]->val<=res[i-1]->val) return false;
       }
       return true;
     }
};
