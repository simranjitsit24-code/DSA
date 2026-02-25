#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int m,int n,vector<vector<int>>& image,int i,int j,int c, vector<vector<bool>>& vis,int color)
    {
        if (i>=m || j>=n || j<0||i<0||image[i][j]!=c||vis[i][j]) return;

        vis[i][j]=true;
        image[i][j] = color;
        dfs(m,n,image,i-1,j,c,vis,color);
        dfs(m,n,image,i,j-1,c,vis,color);
        dfs(m,n,image,i+1,j,c,vis,color);
        dfs(m,n,image,i,j+1,c,vis,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        dfs(m,n,image,sr,sc,image[sr][sc],vis,color);
        return image;
    }
};