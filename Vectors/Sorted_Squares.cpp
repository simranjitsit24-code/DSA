#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
       int n = nums.size();
       vector<int> freq(10001,0);
       vector<int> ans;
       for(int i: nums)
       {
        if (i<0)
        {
            i = -i;
        }
        freq[i]++;
       }
       for(int i=0;i<=10000;i++)
       {
        while(freq[i])
        {
            ans.push_back(i*i);
            freq[i]--;
        }
       }
       return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result = sol.sortedSquares(nums);
    cout << "Sorted squares: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}