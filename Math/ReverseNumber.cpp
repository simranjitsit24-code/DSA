#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long reverse(int x) 
    {
      long long num = 0;
    while (x)
    {
     int r = x%10;
     num = num*10 + r;
     x = x/10;
    }
  if (num > INT_MAX || num < INT_MIN)
            return 0;

    return num;
    }
};
int main()
{
    Solution sol;
    int number = -12345;
    long long reversedNumber = sol.reverse(number);
    cout << "Reversed Number: " << reversedNumber << endl;
    return 0;
}