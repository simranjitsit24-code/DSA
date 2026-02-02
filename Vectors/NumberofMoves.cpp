#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int abs(int a)
    {
        return (a<0)? -a:a;
    }
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        vector<int> freq(102,0);
        for (int i:seats)
        {
            freq[i]++;
        }
        seats.clear();
        for (int i=0;i<=100;i++)
        {
            while(freq[i]>0)
            {
                seats.push_back(i);
                freq[i]--;
            }
        }
         vector<int> freq2(101,0);
         for (int i:students)
        {
            freq2[i]++;
        }
        students.clear();
        for (int i=0;i<=100;i++)
        {
            while(freq2[i]>0)
            {
                students.push_back(i);
                freq2[i]--;
            }
        }
        int sum = 0;
        for (int i=0;i<seats.size();i++)
        {
          sum+= abs(seats[i]-students[i]);  
        }
        return sum;
        
    }
};
int main()
{
    Solution sol;
    vector<int> seats = {3,1,5};
    vector<int> students = {2,7,4};
    int res = sol.minMovesToSeat(seats,students);
    cout << "The minimum number of moves required is: " << res << endl;
    return 0;
}