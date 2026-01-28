#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector <int> freq(101,0);
        vector <int> comp = heights;
        for (int i:heights)
        {
            freq[i]++;
        }
        int idx =0;
        for (int j=1; j<freq.size();j++)
        {
            int ele = freq[j];
            while (ele)
            {
            
             heights[idx++] = j;
             ele--;
            }
        }
        idx = 0;
        for (int i=0;i<n;i++)
        {
            if (comp[i]!=heights[i]) idx++;
        }
        return idx;
    }
};

int main()
{
    Solution obj;
    vector<int> heights = {1,1,4,2,1,3};
    int result = obj.heightChecker(heights);
    cout << "Number of students not in correct position: " << result << endl;
    return 0;

}