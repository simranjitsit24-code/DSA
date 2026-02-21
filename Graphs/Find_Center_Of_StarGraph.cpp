#include <vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       int n = edges.size();
       int u1 = edges[0][0];
       int v1 = edges[0][1];
       int u2 = edges[1][0];
       int v2 = edges[1][1];
       if (u1==u2) return u1;
       if (v1==v2) return v2;
       if (v1==u1 || v2==u1) return u1;
       if (v2==u2 || v1==u2) return u2;
       return -1;
    }
};