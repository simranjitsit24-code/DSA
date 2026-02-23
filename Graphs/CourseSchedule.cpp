#include<bits/stdc++.h>
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
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        int n = edges.size(); 
        vector<bool> vis(n,false);
          vector<bool> rec(n,false);
        return !iscycle(edges,rec,vis,0);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges = {{1,0},{0,1}};
    cout << s.canFinish(2,edges);
    return 0;
}