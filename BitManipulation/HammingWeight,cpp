#include <iostream>
using namespace std;
int hammingWeight(int n) {
        int count = 0;
        while (n)
        {
            if (n%2==1) count++;
            n = n/2;
        }
        return count;
    }

int main()
{
    int n = 256;
    cout << "The Hamming Weight of " << n << " is: " << hammingWeight(n) << endl;
    return 0;   
}