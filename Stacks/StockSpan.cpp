#include <bits/stdc++.h>
using namespace std;
class StockSpanner {
public: 
    StockSpanner() {
    }
    stack <int>s;
    int next(int price) {
        stack<int> s2;
        int count = 0;
        s.push(price);
        s2 = s;
        while(!s2.empty() && s2.top()<=price)
        {
            count++;
            s2.pop();
        }
        return count;
    }
};  

int main()
{
    StockSpanner* obj = new StockSpanner();
    cout<<obj->next(100)<<endl;
    cout<<obj->next(80)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(70)<<endl;
    cout<<obj->next(60)<<endl;
    cout<<obj->next(75)<<endl;
    cout<<obj->next(85)<<endl;
    return 0;
}