#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string ,vector<pair<string,double>>> g;
    double dfs(string src,string des,unordered_set<string> &vis)
    { 
       
          if (g.find(src) == g.end()) return -1.0;
             if (src == des) return 1.0;
          vis.insert(src);

          for (auto &n : g[src])
          {
            if (!vis.count(n.first))
            {
                double ans = dfs(n.first,des,vis);
                if (ans!=-1)
                {
                    return ans*n.second;
                }
            }
          }
          return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& a, vector<double>& values, vector<vector<string>>& queries)
    {
        int n = values.size();
        vector<double> ans;
        for (int i=0;i<n;i++)
        {
            g[a[i][0]].push_back({a[i][1],values[i]});
            g[a[i][1]].push_back({a[i][0],1.0/values[i]});
        }
        
        for (auto &q : queries)
        {
            unordered_set<string> vis;
            ans.push_back(dfs(q[0],q[1],vis));
        }
        return ans;
    }
};
int main()
{
    vector<vector<string>> a = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> q = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution s;
    vector<double> ans = s.calcEquation(a,values,q);
    for (auto it:ans)
    {
        cout<<it<<" ";
    }
}