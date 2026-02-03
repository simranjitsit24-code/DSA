#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> freq(1001,0);
        for (int i:citations)
        {
            freq[i]++;
        }
        int count=0;
        for (int i = 1000;i>=0;i--)
        {
        while (freq[i]>0)
        {
            if (count>=i)
            {
                return count;
            }
            freq[i]--;
            count++;
        }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> citations = {3,0,6,1,5};
    int h_index = sol.hIndex(citations);
    cout << "The H-index is: " << h_index << endl;
    return 0;
}