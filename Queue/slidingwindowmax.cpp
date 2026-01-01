#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque <int> q;
        vector <int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if (!q.empty()&&q.front()==i-k)
            {
                q.pop_front();
            }
            while (!q.empty()&&nums[q.back()]<nums[i]) 
            {
                q.pop_back();
            }
            q.push_back(i);
            if (i>=k-1)
            {
                ans.push_back(nums[q.front()]);
            }
        }
      return ans;
    }
    int main()
    {
        vector<int> arr = {1,3,-2,4,-3,5,6};
        vector<int> ans = maxSlidingWindow(arr,3);
        for (int i : ans)
        {
            cout<<i<<" ";
        }

    }