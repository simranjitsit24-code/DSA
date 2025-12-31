#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
    bool ispalin(string s)
    {
        string t = s;
        reverse(s.begin(),s.end());
        if (s==t)
        {
       return true;
        }
        else return false;
    }
    void getpartition(vector<vector<string>>& ans,vector<string>& partition,string s)
    {
        if (s.empty()) 
        {
            ans.push_back(partition);
            return;
        }
        for (int i=0;i<s.size();i++)
        {
            string part = s.substr(0,i+1);
            if (ispalin(part))
            {
                partition.push_back(part);
                getpartition(ans,partition,s.substr(i+1));
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> partitions;
        getpartition (ans, partitions,s);
        return ans;
    }

int main()
{
    string  a = "aab";
    vector<vector<string>> ans;
    ans = partition(a);
    for(auto &i : ans)
    {
     for(string x: i)
     {
        cout<<x<<"  ";
     }
    }
}