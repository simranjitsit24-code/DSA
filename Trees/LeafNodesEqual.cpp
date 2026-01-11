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
    void leaf(TreeNode* root)
    {
        if (!root) return;
        if (!root->left && !root->right) ans.push_back(root->val);
        leaf(root->left);
        leaf(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
     {
       leaf(root1);
       vector<int> ans2 = ans;
       ans.clear();
       leaf(root2);
       return ans==ans2;  
    }
};