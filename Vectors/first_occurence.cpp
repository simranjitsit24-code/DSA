#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haysack, string needle)
    {
        int m = haysack.size();
        int n = needle.size();
       for(int i=0;i<m;i++)
       {
        int j = i;
        int k = 0;
        while (j<m && k<n && haysack[j]==needle[k])
        {
           if (k==n-1)
           {
            return i;
           }
           j++;
           k++;
        }
       }  
       return -1;
    }
};
int main()
{
    Solution sol;
    string haysack = "hello";
    string needle = "ll";
    int index = sol.strStr(haysack, needle);
    if (index != -1)
    {
        cout << "The first occurrence of \"" << needle << "\" in \"" << haysack << "\" is at index: " << index << endl;
    }
    else
    {
        cout << "\"" << needle << "\" not found in \"" << haysack << "\"" << endl;
    }
    return 0;
}