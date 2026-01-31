#include <bits/stdc++.h>    
using namespace std;
class Solution {
public:
    string frequencySort(string s) 
    {
        string ans = "";
        int n =  s.size();
        vector <vector<char>> buck(n+1);
        unordered_map<char,int> mp;
        for (char i:s)
        {
            mp[i]++;
        }
        for (auto& i: mp)
        {
            buck[i.second].push_back(i.first);
        }
        for (int i=n;i>=0;i--)
        {
            int j = i;
            int k = 0;
            while (k<buck[i].size())
            {
                while(j)
                {
                ans.push_back(buck[i][k]);
                j--;
                }
                j=i;
                k++;
            }
        }
      return ans;
    }
};