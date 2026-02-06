#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> digits(int n)
    {
        vector<int> dig;
        while (n)
        {
            int x = n%10;
            dig.push_back(x);
            n = n/10;
        }
        return dig;
    }
    bool isHappy(int n) 
    {
        unordered_set <int> seen;
        vector<int> dig = digits(n);
        int s = 0;
        while(s!=1)
        {
        for(int i : dig)
        {
         s+=i*i;
        }
         if (seen.count(s)) return false; 
            seen.insert(s);
        if (s==1) return true;
        dig = digits(s);
        if (s==7 && dig.size()==1 && dig[0]<=3 ) return false;
       
        s = 0;
        }
        return false;
    }
};
int main()
{
    Solution sol;
    int n = 19;
    bool result = sol.isHappy(n);
    cout << "Is " << n << " a happy number? " << (result ? "Yes" : "No") << endl;
    return 0;
}