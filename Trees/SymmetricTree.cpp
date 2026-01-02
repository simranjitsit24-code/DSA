#include <iostream>
using namespace std;
class TreeNode
{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!q && !p) return true;
        if (p && !q) return false;
        if (!p && q) return false; 
        return (p->val == q->val)*isSameTree(p->left,q->right)*isSameTree(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root)
    { 
        if(!root) return true;
        return isSameTree(root->left, root->right);
    }
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if(isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}