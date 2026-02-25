#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool iscycle(vector<vector<int>>& edges,vector<bool> &rec,vector<bool> &vis,int source)
    {
        int n = edges.size();
        vis[source] = true;
        rec[source] = true;
        for (int i=0;i<n;i++)
        {
            int u = edges[i][1];
            int v = edges[i][0];
            if (u==source)
            {
              if(!vis[v])
              {
                if (iscycle(edges,rec,vis,v))
                return true;
              }
              else if (rec[v])
              {
                return true;
              }
            }
          
        }
            rec[source] = false;
            return false;
    }
    void topo(stack<int> &s , int source,vector<vector<int>>& edges,vector<bool>& vis,int n)
    {
        vis[source] = true;
        for (int i=0;i<n;i++)
        {
        int u = edges[i][1];
        int v = edges[i][0];
         if(source==u)
         {
             if (!vis[v])
             {
                topo(s,v,edges,vis,n);
             }
         }
        }
        s.push(source);
    }
    vector<int> findOrder(int num, vector<vector<int>>& edges)
    {
        vector <bool> rec(num,false);
        vector <bool> vis(num,false);
        vector <int> ans;
        if (edges.empty())
        {
            for (int i=0;i<num;i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        for (int i=0;i<num;i++)
        {
        if (!vis[i])
        {
             if (iscycle(edges,rec,vis,i)) 
             {
             return ans;
             }
        }

        }
      stack<int> s;
    for (int i=0;i<num;i++)
        {
        if (!rec[i])
        {
            topo(s,i,edges,rec,edges.size());
        }

        }
      while (!s.empty())
      {
        ans.push_back(s.top());
        s.pop();
      }
      return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = s.findOrder(4,edges);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}