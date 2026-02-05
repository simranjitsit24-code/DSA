#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        vector<int> ans;
        for (int i:nums)
        {
            freq[i]++;
        }
        for (int i:nums)
        {
            if (freq[i]==2) 
            {
                ans.push_back(i);
                freq[i]--;
            }
        }
      return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = sol.findDuplicates(nums);
    cout << "Duplicates in the array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}