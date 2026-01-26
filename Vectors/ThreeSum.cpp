#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set <vector<int>> ans;
        vector <vector<int>> ans2;
        int n = nums.size();
        int j = 0;
        int k = n-1;
        for (int i=0;i<n-2;i++)
        {
           j = i+1;
           k = n-1;
           while (j<k)
           {
            if (nums[j]+nums[k] == -nums[i])
            {
                ans.insert({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }
            else if (nums[j]+nums[k] < -nums[i])
            {
              j++;
            }
            else
            {
             k--;
            }
           }
        }
        for (auto i: ans)
        {
            ans2.push_back(i);
        }
        return ans2;
    }
};

