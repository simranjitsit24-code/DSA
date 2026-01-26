#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int abs(int a)
    {
        return a<0?-a:a;
    }

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int m = INT_MAX;
        vector <vector<int>> ans;
        for (int i=0;i<arr.size()-1;i++)
        {
         m = min(abs(arr[i]-arr[i+1]),m);
        }
        for (int i=0;i<arr.size()-1;i++)
        {
          if (abs(arr[i]-arr[i+1]) == m)  ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
    }
};