#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if (arr.empty()) return false;
        int n = arr.size();
        for (int i=0;i<n;i++)
        {
            int j = 0;
            int k= n-1;
            while (j<=k)
            {
               int mid = j+(k-j)/2;
               if(arr[mid]==(2*arr[i])) 
               {
                 if (mid!=i) return true;
                 else k = mid-1;
               }
               else if (arr[mid]>(2*arr[i]))  
               {
               k = mid-1;
               }
               else j = mid+1;
            }
        }
        return false;
    }
};
int main()
{
    Solution obj;
    vector<int> arr = {10,2,5,3};
    bool result = obj.checkIfExist(arr);
    if(result)
        cout << "There exists an element and its double in the array." << endl;
    else
        cout << "No such elements found in the array." << endl;
    return 0;
}