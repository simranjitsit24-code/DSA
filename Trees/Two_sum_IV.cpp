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
    vector <int> ans;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
     if (!root) return false;
     inorder(root);
     int p =0;
     int q = ans.size()-1;
     while (p<q)
     {
      if (ans[p]+ans[q] == k) return true;
      if (ans[p]+ans[q] < k) p++;
      else q--;
     }
     return false;
     }
};