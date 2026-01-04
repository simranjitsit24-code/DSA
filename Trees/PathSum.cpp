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
    bool ans = false;
    int sum=0;
    void path(TreeNode* root,int target)
    {
        if (!root) return;
        sum = sum + root->val;
        if (!root->left && !root->right && sum==target) ans = true;
        path(root->left,target);
        path(root->right,target);
        sum = sum - root->val;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        path(root,targetSum);
        return ans;
    }
};
int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(1);
    Solution s;
    int target=22;
    if(s.hasPathSum(root,target))
        cout<<"Path with given sum exists";
    else
        cout<<"Path with given sum does not exist";
        
}