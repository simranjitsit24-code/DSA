#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<string> ans;

    void backtrack(string &tiles, vector<bool> &used, string &comb) {
        if (!comb.empty())
            ans.insert(comb);

        for (int i = 0; i < tiles.length(); i++) {
            if (used[i]) continue;

            used[i] = true;
            comb.push_back(tiles[i]);

            backtrack(tiles, used, comb);

            comb.pop_back();
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.size(), false);
        string comb = "";
        backtrack(tiles, used, comb);
        return ans.size();
    }
};
int main()
{
   Solution s;
   string a="AAB";
   cout<<"Number of Possibilities:"<<s.numTilePossibilities(a);

}