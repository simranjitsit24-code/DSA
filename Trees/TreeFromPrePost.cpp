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
    unordered_map<int,int> postindex;
    int preidx = 0;
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder,int l,int r)
    {
        if (l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[preidx++]);
        if (l==r) return root;
        int idx = postindex[preorder[preidx]];
        root->left = construct(preorder,postorder,l,idx);
        root->right = construct(preorder,postorder,idx + 1,r-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        for (int i=0;i<postorder.size();i++)
        {
            postindex[postorder[i]] = i;
        }
        return construct(preorder,postorder,0,postorder.size()-1);
    }
};