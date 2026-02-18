#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i : stones)
        {
            pq.push(i);
        }
        while (pq.size()>=2)
        {
           int top1  = pq.top();
           pq.pop();
           if (pq.empty()) return top1;
           int top2  = pq.top();
           pq.pop();
           int x = top2>top1? top2-top1 : top1 - top2;
           pq.push(x);
        }
        return pq.top();

    }
};
int main()
{
    vector<int> stones = {2,7,4,1,8,1};
    Solution s;
    cout << s.lastStoneWeight(stones) << endl;
    return 0;
}