#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n<2) return 0;
        int ans = INT_MIN;
        for (int i = 0 ; i<n-1;i++)
        {
            ans = max(ans, nums[i+1]-nums[i]);
            
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {3,6,9,1};
    int result = obj.maximumGap(nums);
    cout << "Maximum gap: " << result << endl;
    return 0;
}