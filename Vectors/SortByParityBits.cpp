#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> even;
        vector<int> ans;
        for (int i: nums)
        {
            if(i%2==0)
            {
             even.push_front(i);
            }
            else
            {
             even.push_back(i);
            }
        }
        for(int i:even)
        {
          ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3,1,2,4};
    vector<int> result = sol.sortArrayByParity(nums);
    cout << "Array sorted by parity: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}