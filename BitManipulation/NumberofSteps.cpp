#include <bits/stdc++.h>
using namespace std;
int numberOfSteps(int num) 
    {
        int count=0;
        while (num)
        {
            if (num%2==0)  num = num>>1;
            else num = num^1;
            count++;
        }
        return count;
    }
int main()
{
    int num = 14;
    cout << "Number of steps to reduce " << num << " to zero is: " << numberOfSteps(num) << endl;
    return 0;
}