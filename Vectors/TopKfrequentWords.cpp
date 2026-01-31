#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<vector<string>> buck(words.size()+1);
        vector<string> ans;
        int n = words.size();
        if (n==1) return {words[0]};
        for (string i : words)
        {
            mp[i]++;   
        }

        for (auto& i : mp)
        {
            buck[i.second].push_back(i.first);
        }
        
        for (int i=n;i>=0 && ans.size()<k;i--)
        {
            if (!buck[i].empty())
            {
                sort(buck[i].begin(),buck[i].end());
            for (string j : buck[i])
            {

               ans.push_back(j); 
                if (k==ans.size()) break;
            }
            if (k==ans.size()) break;
            }
        }
        return ans;

    }
};
int main()
{
    Solution sol;
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;
    vector<string> res = sol.topKFrequent(words,k);
    cout << "The top " << k << " frequent words are: ";
    for (string i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}