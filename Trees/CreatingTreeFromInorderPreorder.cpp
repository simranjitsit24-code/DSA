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
    int preidx = 0;
    unordered_map<int,int> mp;
    TreeNode* build(vector<int>& preorder,int l,int r)
    {
        if (l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[preidx++]);

        if (l==r) return root;
        
        root->left = build(preorder,l,mp[root->val]-1);
        root->right = build(preorder,mp[root->val]+1,r);
         
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
        return build(preorder,0,inorder.size()-1);
    }
};