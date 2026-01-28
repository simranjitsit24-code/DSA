#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        int idx=0;
        sort(nums.begin(),nums.end());
        for (int j=0;j<n-1;j++)
        {
           idx += min(nums[j],nums[j+1]);
           j++;
        }
        return idx;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1,4,3,2};
    int result = obj.arrayPairSum(nums);
    cout << "Maximum sum of min pairs: " << result << endl;
    return 0;
}