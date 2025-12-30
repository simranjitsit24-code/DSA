#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

    bool isValid(string s) 
    {
        stack <char>st;
        unordered_map <char,char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        
        int n = s.length();
        for (int i=0;i<n;i++)
        {
         if (!st.empty()&&m[st.top()]==s[i])
         {
             st.pop();
             continue;
         }
         
         st.push(s[i]);
        }
        if (st.empty()) return true;
        else return false;
        
    }
    int main()
    {
        string s = "{[]}";
        if (isValid(s))
        {
            cout<<"Valid Parenthesis"<<endl;
        }
        else
        
        {
            cout<<"Invalid Parenthesis"<<endl;
        }
        return 0;
    }