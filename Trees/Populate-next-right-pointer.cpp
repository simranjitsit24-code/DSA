#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    vector<vector<Node*>> ans;
    void level(Node* root)
    {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector <Node*> level;
            for (int i=0;i<size;i++)
            {
                Node* front = q.front();
                q.pop();
                level.push_back(front);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
             }
             ans.push_back(level);
        }
    }
    Node* connect(Node* root)
     {
       level(root);
       for (auto i :ans)
       {
        for (int j=0;j<i.size()-1;j++)
        {
            i[j]->next = i[j+1];
        }
        i.back()->next = nullptr;
       }
       return root;
    }

};