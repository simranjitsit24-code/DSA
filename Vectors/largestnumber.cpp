#include <bits/stdc++.h>
using namespace std;
bool compare(string a, string b)
{
    return a+b > b+a;
}
string largestNumber(vector<int>& nums) {
          vector<string> strNums;
          for (int i: nums)
          {
              strNums.push_back(to_string(i));  
          }
            sort(strNums.begin(), strNums.end(), compare);
            string result;
            for (string s: strNums)
            {
                result += s;
            }
            if (result[0] == '0')
            {
                return "0";
            }
            return result;
}
int main()
{    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;    return 0;
}