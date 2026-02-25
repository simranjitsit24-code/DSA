#include <bits/stdc++.h>
using namespace std;
void kahn(list<int> adj[],vector<vector<int>>& edges, vector<int>& indegree, vector<int>& ans)
{
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
}
int main()
{
    vector<vector<int>> edges = {{1,0},{2,0},{3,1},{3,2}};
    int num = 4;
    list<int> adj[num];
    vector<int> indegree(num,0);
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i][1];
        int v = edges[i][0];
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int> ans;
    kahn(adj, edges,indegree, ans);
    for (auto it:ans){
        cout<<it<<" ";  
    }
}