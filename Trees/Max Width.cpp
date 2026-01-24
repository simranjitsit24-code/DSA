#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans = 0;
        while (!q.empty())
        {
          
          int size = q.size();
          long long start = 0;
          long long end = 0;
          long long minIndex = q.front().second;
          for (int i=0;i<size;i++)
          {
            auto [node,idx] = q.front();
            q.pop();
            idx -= minIndex;
            if (i == 0) start = idx;
            if (i == size-1) end = idx;
            if (node->left) q.push({ node->left , 2*idx + 1 });
            if (node->right) q.push({ node->right , 2*idx + 2});
          }
          ans = max(ans,end-start + 1);
        }
        return ans;
    }
};