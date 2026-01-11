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
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (!root) return "null,";
        s = s + to_string(root->val)+",";
        s = s + serialize(root->left) + serialize(root->right);
        return s;
    }
    TreeNode* build(queue<string> &q)
    {

         string front = q.front();
         q.pop();
         if (front=="null") return nullptr;
         TreeNode* newn = new TreeNode(stoi(front));
         newn->left = build(q);
         newn->right = build(q);
         return newn;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        queue <string> q;
        string t = "";
        for (char c : data)
        {
            if (c == ',')
            {
                q.push(t);
                t.clear();
            }
            else
            {
                t = t+c;
            }
        }
        return build(q);

    }
};