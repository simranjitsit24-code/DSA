#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string revers(string a)
    {
        int i=0;
        int j=a.size()-1;
        while (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        return a;
    }
    string toHex(int num) {
        if (num==0) return "0";
        string ans = "";
        unsigned int a = num;
        vector<char> ch = {'a','b','c','d','e','f'};
       while (a)
       {
        int r = a%16;
        if (r>=0 && r<=9) ans+=to_string(r);
        else 
        {
            ans.push_back(ch[r%10]);
        }
        a=a/16;
       }
       return revers(ans);
    }
};

int main ()
{
    Solution sol;
    int num = 26;
    cout << sol.toHex(num) << endl;
    return 0;
}