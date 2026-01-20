#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            if (n == 2) {
                ans.push_back(-1);
            } else {
                for (int i = 0; i < 31; ++i) {
                    if (!(n & (1 << i))) {
                        ans.push_back(n ^ (1 << (i - 1)));
                        break;
                    }
                }
            }
        }
        return ans;
    }
};