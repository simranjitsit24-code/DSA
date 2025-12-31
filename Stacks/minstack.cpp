#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    MinStack() {
        
    }
    stack <pair<int,int>> st;
    void push(int val) 
    {
        int m = st.empty() ? val : min(val, st.top().second);
        st.push({val , m});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() 
    {
        return st.top().second;
    }
};
int main()
{
    MinStack st;
    st.push(-23);
    st.push(5);
    st.push(12);
    st.pop();
    cout<<"Minimum Element : "<<st.getMin();
    return 0;
}