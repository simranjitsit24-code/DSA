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
 void ans(TreeNode* root, string &s, vector<string> &a)
    {
        if (!root) return;

        int len = s.length();  

        s += to_string(root->val);

        if (!root->left && !root->right)
        {
            a.push_back(s);
        }
        else
        {
            s += "->";
            ans(root->left, s, a);
            ans(root->right, s, a);
        }

        s.resize(len);          
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> a;
        string s = "";
        ans(root, s, a);
        return a;
    }
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    vector<string> paths = binaryTreePaths(root);
    for (const string& path : paths) {
        cout << path << endl;
    }
    return 0;
}
