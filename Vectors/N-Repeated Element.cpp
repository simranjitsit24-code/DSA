#include <iostream>
#include <vector>   
#include <algorithm>
using namespace std;
int repeatedNTimes(vector<int>& nums)
     {
        for (int i=0;i<nums.size();i++)
        {
            int cnt = count(nums.begin(),nums.end(),nums[i]);
            if (cnt==(nums.size()/2))
            {
                return nums[i];
            }
        }
        return -1;
    }
    int main()
    {
        vector<int> nums = {5,1,5,2,5,3,5,4};
        cout << "The element repeated N times is: " << repeatedNTimes(nums) << endl;
        return 0;
    }