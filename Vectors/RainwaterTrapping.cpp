#include<bits/stdc++.h>
using namespace std;
vector<int> rightmax(vector<int> height)
    {
        int m = -1;
        vector<int> ans(height.size());
        for (int i=0;i<height.size();i++)
        {
            m = max(m,height[i]);
            ans[i] = m;
        }
        
        return ans;
    }
    vector<int> leftmax(vector<int> height)
    {
        int m=-1;
        vector<int> ans(height.size());
        for (int i=height.size()-1;i>=0;i--)
        {
            m  = max(m,height[i]);
            ans[i] = m;
        }
        return ans;
    }
    int trap(vector<int>& height) 
    {
        vector<int> left = leftmax(height);
        vector<int> right = rightmax(height);
        int sum = 0;
        for (int i=0;i<height.size();i++)
        {
         sum = sum +(min(left[i],right[i])-height[i]);
        }
        return sum;
    }

int main()
{
   vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<"Amount of water"<<trap(height);
}