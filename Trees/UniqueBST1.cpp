#include <iostream>
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
class Solution {
public:
    long long numTrees(int n) {
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * 2 * (2*i + 1) / (i + 2);
        }
        return res;
    }
};