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
    vector<int> ans;
    int m = INT_MAX;
    void mindiff(TreeNode* root)
    {
        if (!root) return;
        mindiff(root->left);
        ans.push_back(root->val);
        mindiff(root->right);
     }
    int minDiffInBST(TreeNode* root) 
    {
        mindiff(root);
        for (int i=0;i<ans.size()-1;i++)
        {
            m = min(m,ans[i+1]-ans[i]);
        }
        return m;
    }
};