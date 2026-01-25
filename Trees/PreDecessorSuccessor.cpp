#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector <int> findPredecessorSuccessor(TreeNode* root, int key)
{
    TreeNode* curr = root;
    if (root == NULL)
        return {-1, -1};
    TreeNode* predecessor = NULL;
    TreeNode* successor = NULL;
    while (curr != NULL)
    {
        if (curr->val==key)
        {
            if (curr->left)
            {
                TreeNode* temp = curr->left;
                while (temp->right)
                    temp = temp->right;
                predecessor = temp;
            }
            if (curr->right)
            {
                TreeNode* temp = curr->right;
                while (temp->left)
                    temp = temp->left;
                successor = temp;
            }
        }
    }
    while (curr->val > key)
    {
        successor = curr;
        curr = curr->left;
    }
    while (curr->val < key)
    {
        predecessor = curr;
        curr = curr->right;
    }
    return {(predecessor != NULL) ? predecessor->val : -1, (successor != NULL) ? successor->val : -1};
}
int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(8);
    root->right->right = new TreeNode(9);
    vector <int> ans;
    ans = findPredecessorSuccessor(root, 6);
    cout << "Predecessor: " << ans[0] << ", Successor: " << ans[1] << endl;
    return 0;
}