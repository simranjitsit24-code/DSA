#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int i=0;
       int counta = 0;
       int countb = 0;
       int countc = 0;
       int n = nums.size();
       while(i+1<n && nums[i]<nums[i+1])
       {
        i++;
        counta++;
       }
       if (i==n-1) return false;
       while(i+1<n && nums[i]>nums[i+1])
       {
        i++;
        countb++;
       }
       if (i==n-1) return false;
        while(i+1<n && nums[i]<nums[i+1])
       {
        i++;
        countc++;
       }
       return i==n-1 && counta && countb && countc;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1,3,5,4,2,6,8};
    if (sol.isTrionic(nums))
    {
        cout << "The array is trionic." << endl;
    }
    else
    {
        cout << "The array is not trionic." << endl;
    }
    return 0;
}