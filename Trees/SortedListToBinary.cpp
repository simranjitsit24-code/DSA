#include<bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    TreeNode* bst(ListNode* head)
    {
        if (!head) return nullptr;
       if (!head->next) return new TreeNode(head->val);
       ListNode* slow = head;
       ListNode* fast = head;
       ListNode* prev = nullptr;
       while(fast && fast->next)
       {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
       }
       prev->next = nullptr;
       TreeNode* root = new TreeNode(slow->val);
       root->left = bst(head);
       root->right = bst(slow->next);
       return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head)
     {
       return bst(head);
    }
};