#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    { 
        int n = nums.size();
        vector<int> ans2;
        int i=0;
        int j= n-1;
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
          ans2.push_back(i);
        }
        while (i<=j)
        {
        ans.push_back(ans2[i++]);
        ans.push_back(ans2[j--]);
        } 
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4,2,5,7};
    vector<int> result = sol.sortArrayByParityII(nums);
    cout << "Array sorted by parity II: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}