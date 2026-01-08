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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     unordered_map <int,int> mp;
     TreeNode* build(vector<int>& postorder,int l,int r,int preidx)
    {
        if (l>r||preidx<0) return nullptr;
        TreeNode* root = new TreeNode(postorder[preidx--]);
        int mid = mp[root->val];
        if (l==r) return root;

        root->right = build(postorder,mid+1,r,preidx);
        root->left = build(postorder,l,mid-1,preidx);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for (int i = 0 ; i<inorder.size();i++)
        {
          mp[inorder[i]] = i;
        }
       return build(postorder,0,inorder.size()-1,inorder.size()-1);
    }
};
