#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
         sort(nums.begin(),nums.end());
         set <vector<int>>se;
         vector<vector<int>> v;
         long long l = 0;
         long long n = nums.size()-1;
         long long m = n;
         for (int i=0;i<=n-3;i++)
         {
            for (int j=i+1;j<=n-2;j++)
            {
                m = n;
                long long s = nums[i]+nums[j];
                l = j+1;
                while (l<m)
                {
                    long long sum = s + nums[l] + nums[m];
                    if (sum==target) 
                    {
                        se.insert({nums[i],nums[j],nums[l],nums[m]});
                        l++;
                        m--;
                    }
                    else if (sum < target) l++;
                    else m--;
                }
            }
         }
         for (auto i: se)
         {
            v.push_back(i);
         }
         return v;
    }
};

int main ()
{
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = sol.fourSum(nums, target);
    cout << "Unique quadruplets that sum to " << target << " are:" << endl;
    for ( auto& quad : result)
    {
        cout << "[";
        for (long long i = 0; i < quad.size(); ++i)
        {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}