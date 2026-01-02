#include <iostream>
using namespace std;
int hammingDistance(int x, int y) 
    {
        int suma = x^y;
        int count=0;
        while (suma)
        {
            if (suma%2==1) count++;
            suma /=2;
        }
        return count;
    }
int main()
{
    int x = 1, y = 4;
    cout << "The Hamming Distance between " << x << " and " << y << " is: " << hammingDistance(x, y) << endl;
    return 0;
}