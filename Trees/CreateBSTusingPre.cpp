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
    int idx=0;
    TreeNode* pre(vector<int>& preo ,int bound)
     {
       if (idx==preo.size() || bound < preo[idx]) return nullptr;
       TreeNode* root = new TreeNode(preo[idx++]);
       root->left = pre(preo,root->val);
       root->right = pre(preo,bound);
       return root;
     }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
       
       return pre(preorder, INT_MAX);
    }
};