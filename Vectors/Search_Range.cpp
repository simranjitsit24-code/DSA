#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        bool found = false;
        int n = nums.size()-1;
        if (nums.empty()) return{-1,-1};
        vector<int> ans;
        int i = 0;
        while  (i<=n)
        {
          int mid = i+(n-i)/2;
          if (nums[mid]==target)
          {
            found = true;
            int left = mid, right = mid;

                while (left - 1 >= 0 && nums[left - 1] == target)
                    left--;

                while (right + 1 <= n && nums[right + 1] == target)
                    right++;

                return {left, right};
          }
          else if (nums[mid]<target)
          {
            i = mid+1;
          }
          else 
          {
            n = mid-1;
          }
        }
        if (!found) return{-1,-1};
        return ans;
    }
};