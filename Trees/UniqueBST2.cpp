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
    vector<TreeNode*> solve(int start,int end)
    {
        if (start>end) return {nullptr};
        vector<TreeNode*> res;
        for (int t=start;t<=end;t++)
        {
            vector<TreeNode*> lefttree = solve(start,t-1);
            vector<TreeNode*> righttree = solve(t+1,end);

            for (auto left:lefttree)
            {
                for (auto right:righttree)
                {
                    TreeNode* root = new TreeNode(t);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }  
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
       if (n==0) return {};
       return solve(1,n);
    }
};
