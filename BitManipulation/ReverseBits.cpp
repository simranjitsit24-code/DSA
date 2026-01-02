#include <iostream>
#include <string>
using namespace std;
long int reverseBits(int n)
     {
        string s = "";
        for (int i = 0; i < 32; i++)
    {
        if (n % 2 == 0) s.push_back('0');
        else s.push_back('1');
        n /= 2;
    }
        long int sum = 0;
        long int flag = 1;
       for (int i = s.length()-1;i>=0;i--)
       {
        sum = sum + (s[i]-'0')*flag;
        flag = flag*2;
       }
       return sum;
    }
int main()  
{
    int n = 43261596;
    cout << "The reversed bits of " << n << " is: " << reverseBits(n) << endl;
    return 0;
}