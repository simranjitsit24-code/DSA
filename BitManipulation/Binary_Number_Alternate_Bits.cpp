#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        string s="";
        while (n)
        {
            if (n%2==1) s.push_back('1');
            else s.push_back('0');
            n/=2;
        }
        for (int i=0;i<s.length()-1;i++)
        {
          if (s[i]==s[i+1]) return false;  
        }
        return true;
    }
};