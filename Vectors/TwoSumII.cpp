#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if (nums.empty()) return{-1,-1};
        int l=0;
        int h = n-1;
        while (l>=0 && h<n && l<=h )
        {
            if (target == nums[l]+nums[h]) return {l+1,h+1};
            else if (target > nums[l]+nums[h]) l++;
            else h--;
        }
        return {-1,-1};
    }
};
int main ()
{
    Solution obj;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = obj.twoSum (nums,target);
    for (auto x: res) cout<<x<<" ";
    return 0;
}