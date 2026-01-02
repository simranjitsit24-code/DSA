#include<iostream>
#include<vector>
using namespace std;
vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
    
int main()
{
    int n = 5;
    vector<int> result = countBits(n);
    cout << "The count of 1's in binary representation from 0 to " << n << " is: ";
    for (int i = 0; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}