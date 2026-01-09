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
     vector<int> ans;
     void soln(TreeNode* root,int sum)
     {
        if (!root) return;
        sum = 10*sum + root->val;
        if (!root->left && !root->right) 
        {
         ans.push_back(sum);
         sum = sum - root->val;
        }
        soln(root->left,sum);
        soln(root->right,sum);
        
     }
    int sumNumbers(TreeNode* root) {
        soln(root,0);
        int sum =0;
        for (int i: ans)
        {
            sum += i;
        }
        return sum;
    }
};