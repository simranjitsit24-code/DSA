#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3,0);
        for (int i:nums)
        {
            freq[i]++;
        }
        nums.clear();
        for (int i=0;i<3;i++)
        {
            while (freq[i])
            {
                nums.push_back(i);
                freq[i]--;
            }
        }
       
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    cout << "The sorted colors are: ";
    for (int i:nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}