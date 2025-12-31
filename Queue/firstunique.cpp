#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
        unordered_map <char,int> m;
        queue<int > q;
        for (int i = 0; i<s.length();i++)
        {
            if (m.find(s[i])==m.end())
            {
                q.push(i);
            }
            m[s[i]]++;
            while(q.size()>0 && m[s[q.front()]]>1) q.pop();
        }
        return q.empty()?-1:q.front();
        
    }
int main()
{
    string s = "level";
    cout<<"First unique character index"<<firstUniqChar(s);
}