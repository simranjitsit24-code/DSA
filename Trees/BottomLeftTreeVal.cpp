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

    int answer(TreeNode* root)
    {
        if (!root) return -1;
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty())
        {
            int size = q.size();
            for (int i=0;i<size;i++)
            {
                TreeNode* front = q.front();
                if (i==0) ans = front->val;
                q.pop();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }
        return ans;
    }
    int findBottomLeftValue(TreeNode* root) 
    {
       return answer(root);
    }
};