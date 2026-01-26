#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> a;
        if (nums.empty()) return a;
        string ans="";
        int n = nums.size();
        for (int i=0;i<n;i++)
        {
            int s = nums[i];
            while (i+1<n && nums[i+1]==nums[i]+1)
            {
             i++;
            }
            int r = nums[i];
           if (s==r) 
           {
            ans = ans+to_string(s);
           }
           else
           {
            ans = ans+ to_string(s);
            ans = ans+"->";
            ans = ans+ to_string(r);
           }
           a.push_back(ans);
           ans="";
        }

        return a;

    }
};