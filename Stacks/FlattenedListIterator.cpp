#include <bits/stdc++.h>
using namespace std;
/**
 * LeetCode Problem 341: Flatten Nested List Iterator
 *
 * NOTE:
 * NestedInteger is a LeetCode-provided interface.
 * Its implementation is hidden and should NOT be implemented.
 */
class NestedIterator {
public:
    stack<NestedInteger> st;  
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        for (int i = nestedList.size()-1;i>=0;i--)
        {
            st.push(nestedList[i]);
        }
    }
    
    int next()
    {
        int val = st.top().getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext()
    {
        while (!st.empty())
        {
            if (st.top().isInteger()) return true;
            auto it = st.top().getList();
            st.pop(); 
            for (int i=it.size()-1;i>=0;i--)
            {
                st.push(it[i]);
            }
        }
        return false;
    }
};