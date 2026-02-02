#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int n = nums.size();
        vector<int> ans(n,0);
        int ct = 0;
        for (int i:nums)
        {
            pro = pro*i;
            if (i==0) ct++;
        }
        if (ct>=2) return ans;
        for (int i=0;i<n;i++)
        {
            int prod = 1;
            //to handle zeroes case
            if (nums[i]==0)
            {
                int l = i-1;
                int r = i+1;
                while(l>=0 || r<n)
                {
                    if (l>=0) 
                    {
                        prod = prod*nums[l--];
                    }
                    if(r<n)
                    {
                        prod = prod*nums[r++];
                    }
                }
                ans[i] = prod;
            }
            else 
            {
                ans[i] = pro/nums[i];
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.productExceptSelf(nums);
    cout << "The product array except self is: ";
    for (int i:res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}