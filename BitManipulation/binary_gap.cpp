#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binaryGap(int n) {
        int m = 0;
        vector<int> ans;
        while (n)
        {
            int x = n%2;
            ans.push_back(x);
            n=n/2;
        }
        reverse(ans.begin(), ans.end());
        int l = ans.size();
        for (int i=0;i<l-1;i++)
        {
            int ct = 1;
            if (ans[i]==1)
            {
                int j = i+1;
                int ct = 1;
                while (j<l && ans[j]==0)
                {
                    ct++;
                    j++;
                }

               if (j<l && ans[j]==1 )
               {
                ct++;
                m = max(m,ct-1);
               }
            }
        }
        return m;
    }
};
int main()
{
    int n = 22;
    Solution s;
    cout << s.binaryGap(n) << endl;
    return 0;
}