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
    
    void get(TreeNode* root,vector<int>& a)
    {
        if (!root) return;
        get(root->left,a);
        a.push_back(root->val);
        get(root->right,a);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector <int> v1;
        vector <int> v2;
        get(root1,v1);
        get(root2,v2);
        int n1 = v1.size();
        int n2 = v2.size();
        vector<int> v3(n1+n2);
        int i = 0;
        int a = 0;
        int b = 0;
        while(a<n1 && b<n2)
        {
           if(v1[a]<=v2[b]) v3[i++] = v1[a++];
           else v3[i++] = v2[b++];
        }
          while (a<n1)
          {
            v3[i++] = v1[a++];  
          }
          while (b<n2)
          {
            v3[i++] = v2[b++];  
          }
          return v3;
    }
};
int main()
{
    Solution sol;
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    vector<int> result = sol.getAllElements(root1, root2);
    cout << "All elements in both BSTs: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}