#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &vis,int m,int n)
    {
        if(i<0 || j<0 || i>=n || j>=m||grid[i][j]!='1'||vis[i][j]) return;
        vis[i][j] = true;
        dfs(i-1,j,grid,vis,m,n);
        dfs(i,j+1,grid,vis,m,n);
        dfs(i,j-1,grid,vis,m,n);
        dfs(i+1,j,grid,vis,m,n);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int island = 0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]=='1' && !vis[i][j])
                {
                  dfs(i,j,grid,vis,m,n);
                  island++;
                }
            }
        }
        return island;
    }
};
int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;
    cout << "Number of islands: " << s.numIslands(grid) << endl;
    return 0;
}