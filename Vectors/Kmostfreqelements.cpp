#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<vector<int>> buck(nums.size()+1);
        vector<int> ans;
        int n = nums.size();
        if (n==1) return {nums[0]};
        for (int i: nums)
        {
            mp[i]++;   
        }

        for (auto& i : mp)
        {
            buck[i.second].push_back(i.first);
        }
        
        for (int i=n;i>=0 && ans.size()<k;i--)
        {
            for (int j : buck[i])
            {
               ans.push_back(j); 
            }
            if (k==ans.size()) break;
        }
        return ans;

    }
};
int  main()
{
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = sol.topKFrequent(nums,k);
    cout << "The top " << k << " frequent elements are: ";
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}