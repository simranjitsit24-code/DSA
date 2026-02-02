#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001,0);
        vector<int> result;
       
        for (int i: arr1)
        {
            freq[i]++;
        }
        for (int i: arr2)
        {
            while (freq[i])
            {
              result.push_back(i);
              freq[i]--;
            }
        }
       for (int i = 0; i <= 1000; i++) {
            while (freq[i] > 0) {
                result.push_back(i);
                freq[i]--;
            }
        }
      return result;
    }
};
int main()
{
    Solution sol;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> res = sol.relativeSortArray(arr1,arr2);
    cout << "The result array is: ";
    for (int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}