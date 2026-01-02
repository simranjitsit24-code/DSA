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
        return (p->val == q->val)*isSameTree(p->left,q->left)*isSameTree(p->right,q->right);
    }

    int main()
    {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);

        if(isSameTree(p, q))
            cout << "The trees are the same." << endl;
        else
            cout << "The trees are not the same." << endl;

        return 0;
    }   