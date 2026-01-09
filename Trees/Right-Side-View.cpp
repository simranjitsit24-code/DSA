#include<bits/stdc++.h>
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
    vector<vector<TreeNode*>> ans;
    void level(TreeNode* root)
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector <TreeNode*> level;
            for (int i=0;i<size;i++)
            {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
             }
             ans.push_back(level);
        }
    }
    vector<int> rightSideView(TreeNode* root)
     {
        level(root);
        vector<int> a;
        for (auto i: ans)
        {
            a.push_back(i.back()->val);
        }
        return a;
    }
};