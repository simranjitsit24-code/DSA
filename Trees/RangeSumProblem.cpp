#include <iostream>
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
    int sums = 0;
    void sum(TreeNode* root, int low, int high)
    {
      if (!root) return;
    if (root->val>=low && root->val<=high) 
      {
        sums+= root->val;
      }
      sum(root->right,low,high);
    sum(root->left,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum(root,low,high);
        return sums;
        
    }
};