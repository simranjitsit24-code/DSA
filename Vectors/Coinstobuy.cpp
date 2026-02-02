#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector <int> freq(100001,0);
        vector <int> ans;
        for (int i:costs)
        {
           freq[i]++;
        }
      for  (int i= 1; i <= 100000; i++)
        {
            while (freq[i]>0)
            {
                ans.push_back(i);
                freq[i]--;
            }
        }
        int count = 0;
        for (int i : ans) {
            if (coins >= i) {
                coins -= i;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
    int res = sol.maxIceCream(costs,coins);
    cout << "The maximum number of ice creams that can be bought is: " << res << endl;
    return 0;
}