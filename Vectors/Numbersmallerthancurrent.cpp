#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        ans = nums;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <int> ans2;
            for (int j=0;j<n;j++)
            {
                int tar = ans[j];
                 for (int k = 0 ; k<n;k++)
                 {
                    if (nums[k]==tar)
                    {
                        ans2.push_back(k);
                        break;
                    }
                 }
            }
          return ans2;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {8,1,2,2,3};
    vector<int> res = sol.smallerNumbersThanCurrent(nums);
    cout << "The result array is: ";
    for (int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}