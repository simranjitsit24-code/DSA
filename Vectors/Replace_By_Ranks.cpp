#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        int n = arr.size();
        int rank=1;
        for (int i=0;i<n;i++)
        {
         if (mp.find(arr[i])==mp.end())
         { mp[arr[i]] = rank;
         rank++;}
        }
         for (int i=0;i<n;i++)
        {
         ans[i] = mp[ans[i]];
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {40, 10, 20, 30};
    vector<int> result = sol.arrayRankTransform(arr);
    cout << "Array after replacing by ranks: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}