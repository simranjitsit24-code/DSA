#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<string> ans;
     vector<int> hours = {1,2,4,8};
     vector<int> minute = {1,2,4,8,16,32};
    void time(int l,int hrs,int min,int led)
    {

     if (hrs>11||min>59) return;
     if (led==0)
     {
     string time = to_string(hrs);
     time+=":";
     if (min<10) time+="0";
     time+=to_string(min);
     ans.push_back(time);
     return;
     }
     if (l==10) return;
     if (l<4) time(l+1,hrs+hours[l],min,led-1);
     else time(l+1,hrs,min+minute[l-4],led-1);
     time(l+1,hrs,min,led);
    }
    vector<string> readBinaryWatch(int turnedOn) 
    {
        time(0,0,0,turnedOn);
        return ans;
    }
};
int main()
{
    Solution obj;
    int turnedOn = 1; 
    vector<string> result = obj.readBinaryWatch(turnedOn);
    for (const string& time : result) {
        cout << time << endl;
    }
    return 0;
}