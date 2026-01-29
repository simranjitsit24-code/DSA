#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(long long c) 
    {
       long long i=0;
       long long j= sqrt(c);
       while (i<=j)
       {
        long long sum = i*i + j*j;
        if (sum == c) return true;
        else if (sum<c) i++;
        else j--;
       }
       return false;
    }        
};

int main ()
{
    Solution sol;
    long long c = 5;
    if (sol.judgeSquareSum(c))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}