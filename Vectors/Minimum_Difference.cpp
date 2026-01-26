#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==1) return 0;
        sort(nums.begin(),nums.end());
        int m=INT_MAX;
        int low = 0;
        int high = low + k-1;
        for (int i=0;i<n && high<n; i++)
        {
           m = min(m,nums[high]-nums[low]);
           low++;
           high++;
        }
        return m;
    }
};