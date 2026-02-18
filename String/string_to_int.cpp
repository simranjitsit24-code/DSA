#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string ans) {
    bool neg = false;
    long long n=0;
    int i=0;
      while (i<ans.size() && ans[i] == ' ')
        {
            i++;
        }
         if (i < ans.size() && (ans[i] == '-' || ans[i] == '+')) {
            if (ans[i] == '-')
                neg = true;
            i++;
        }
         while (i < ans.size() && isdigit(ans[i])) {
            int x = ans[i] - '0';
            n = n * 10 + x;
            if (!neg && n > INT_MAX)
                return INT_MAX;
            if (neg && -n < INT_MIN)
                return INT_MIN;
            i++;
        }
    if (neg)
    {
        n = -n;
    }
    return int(n);
    }
};
int main()
{
    string s = "   -42";
    Solution sol;
    cout << sol.myAtoi(s) << endl;
    return 0;
}