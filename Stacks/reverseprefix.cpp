#include<bits/stdc++.h>
using namespace std;
string reversePrefix(string word, char ch) 
    {
        stack<char> st;
        bool found = false;
        for (char c:word)
        {
            st.push(c);
            if (c==ch )
            {
                found = true;
                 break;
            }
        }
        string ans = "";
        if (st.size()==word.length())
        { 
            if (!found)   return word;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        word.replace(0,ans.length(),ans);
        return word;
    }

    int main()
    {
        string name = "Simranjit";
        string ans = reversePrefix(name , 'n');
        for (char ch: ans)
        {
            cout<<ch<<" ";
        }
    }