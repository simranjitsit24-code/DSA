#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int findComplement(int num)
    {
        int bits = floor(log2(num));
        int flag =1;
        while (bits)
        {
            flag = flag*2;
            bits--;
        }
        int comp  = flag - 1 - num;
        return comp;
    }
};
int main()
{
    Solution sol;
    int num = 5;
    cout << "The complement of " << num << " is: " << sol.findComplement(num) << endl;
    return 0;
}