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
     void answer(TreeNode* root,vector<int> &comb,vector<vector<int>> &ans,int target)
     {
        //If root is null
      if (!root) return;
      //Base case
      comb.push_back(root->val);
      target-=root->val; 
       if (target==0 && !root->left &&!root->right)
      {
        ans.push_back(comb);
        comb.pop_back();
        return;
      }
      answer(root->left,comb,ans,target);
      answer(root->right,comb,ans,target);
      comb.pop_back();

     }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
     {
        vector<int> comb;
        vector<vector<int>> ans;
        answer(root,comb,ans,targetSum);
        return ans;
     }
};