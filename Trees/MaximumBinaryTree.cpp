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
//Montonically decreasing stack approach
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         stack<TreeNode*> st;
//         for (int x : nums) {
//             TreeNode* curr = new TreeNode(x);
//             while (!st.empty() && st.top()->val < x) {
//                 curr->left = st.top();
//                 st.pop();
//             }
//             if (!st.empty()) 
//                 st.top()->right = curr;
//             st.push(curr);
//         }
//         while (st.size() > 1) {
//             st.pop();
//         }
//         return st.top();
//     }
// };
class Solution {
public:
    TreeNode* create(vector<int>& nums,int l,int r)
    {
        if (l>r) return nullptr;
        int m = INT_MIN;
        unordered_map<int,int> mx;
     
        for (int i=l;i<=r;i++)
        {
           mx[nums[i]] = i;
           m= max(m,nums[i]);
        }
        TreeNode* root = new TreeNode(m);
        root->left = create(nums,l,mx[m]-1);
        root->right = create(nums,mx[m]+1,r);
        return root;
    
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return create(nums,0,nums.size()-1);
    }
};
