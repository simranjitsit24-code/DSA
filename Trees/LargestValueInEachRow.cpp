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
    int max(int a, int b)
    {
        return a>b? a:b;
    }
    void answer(TreeNode* root)
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size(); 
            int m = INT_MIN;
            for (int i=0;i<size;i++)
            {
                TreeNode* front = q.front();
                q.pop();
                m = max(m,front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            ans.push_back(m);
        }
        
    }
    vector<int> largestValues(TreeNode* root) 
    {
        answer(root);
        return ans;
    }
};