#include<bits/stdc++.h>
using namespace std;
vector<int> leftsmaller(vector<int> heights)
    {
        vector <int> ans(heights.size());
        stack<int> st;
        for (int i=0;i<heights.size();i++)
        {
           while(!st.empty()&&heights[st.top()]>=heights[i])
           {
             st.pop();
           }
           if (st.empty()) ans[i] = -1;
           else ans[i] = st.top();
           st.push(i);
        }
        return ans;
    }
    vector<int> rightsmaller(vector<int> heights)
    {
        int n = heights.size();
        vector <int> ans(heights.size());
        stack<int> st;
        for (int i=n-1;i>=0;i--)
        {
           while(!st.empty()&&heights[st.top()]>=heights[i])
           {
             st.pop();
           }
           if (st.empty()) ans[i] = n;
           else ans[i] = st.top();
           st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) 
    {
        int ans= 0;
        vector<int> leftans = leftsmaller(heights);
        vector<int> rightans = rightsmaller(heights);
        for (int i=0;i<heights.size();i++)
        {
            ans = max(ans,heights[i]*(rightans[i]-leftans[i]-1));
        }
      return ans;
    }
    int main()
    {
        vector <int> arr = {2,1,5,6,2,3};
        cout<<"Largest Rectangle Area   = "<<largestRectangleArea(arr);
    }