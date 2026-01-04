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
    int height(TreeNode* root)
    {
        if (!root) return 0;
        return max(height(root->left),height(root->right)) + 1;
    }
    int balance(TreeNode* root)
    {
        return height(root->left)-height(root->right);
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (balance(root)>1||balance(root)<-1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }  
};
int main()
{
    
}