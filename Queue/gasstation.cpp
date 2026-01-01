#include <bits/stdc++.h>
using namespace std;
 int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
     {
    
       int start=0;
       int currentfuel = 0;
       int total = 0;
        for (int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            currentfuel+=gas[i]-cost[i];

            if (currentfuel<0)
            {
                start = i+1;
                currentfuel = 0;
            }
        }
        return total>=0?start:-1;
    } 
int main()
{
    vector <int> gas = {1,2,3,4,5};
    vector <int> cost  ={2,3,4,5,1};
    cout<<"Resulting index  = "<<canCompleteCircuit(gas,cost);
}