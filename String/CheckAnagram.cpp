#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t) 
    {
       unordered_map<char,int> mp1;
       unordered_map<char,int> mp2;
       if (s.length()!= t.length()) return false;

       for (int i=0;i<s.length();i++)
       {
        mp1[s[i]]++;
        mp2[t[i]]++;
       }
      
        return mp1==mp2;
    }   
int main()
{
    string s = "anagram";
    string t = "nagaram";
    if (isAnagram(s, t)) {
        cout << s << " and " << t << " are anagrams." << endl;
    } else {
        cout << s << " and " << t << " are not anagrams." << endl;
    }
    return 0;
}