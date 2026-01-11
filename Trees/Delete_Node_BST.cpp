#include <bits/stdc++.h>
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
    TreeNode* findmax(TreeNode* root)
    {
        if (!root) return nullptr;
        while(root->right)
        root = root->right;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root) return nullptr;
        if (root->val < key) root->right =  deleteNode(root->right,key);
        else if (root->val > key) root->left =  deleteNode(root->left,key);
         else 
         {
            if (!root->left && !root->right) return nullptr;
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            TreeNode* dec = findmax(root->left);
            root->val = dec->val;
            root->left = deleteNode(root->left,dec->val);
         }
        
        return root;
    }
};