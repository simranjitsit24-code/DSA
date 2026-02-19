#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct comp
    {
        bool operator()(pair<vector<int>,int> a,pair<vector<int>,int> b)
        {
            return a.second > b.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue <pair<vector<int>,int>,vector<pair<vector<int>,int>> , comp> pq;
        vector<vector<int>> ans2;
        for (int i = 0;i<n;i++)
        {
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({points[i],dis});
        }
        for (int j=k;j>0;j--)
        {
            ans2.push_back(pq.top().first);
            pq.pop();
        }
        return ans2;
    }
};
int main()
{
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;
    Solution s;
    vector<vector<int>> ans = s.kClosest(points,k);
    for (auto &i : ans)
    {
        cout<<"["<<i[0]<<","<<i[1]<<"] ";
    }
}