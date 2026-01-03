#include<bits/stdc++.h>
using namespace std;
vector<int> sortByBits(vector<int>& arr) 
    {
       int z = arr.size();
       vector <pair<int,int>> mp;

       for(int i:arr)
       {
        int count=0;
        pair<int,int> p;
         int y= i;
         while(i)
         {
         if (i%2==1) {
           count++;
         }
         i/=2;
         }
         p.first = count;
         p.second = y;
         mp.push_back(p);
       } 
       sort(mp.begin(),mp.end());
       for(int i=0;i<z;i++)
       {
        arr[i] = mp[i].second;
       }
      return arr;
    }
int main()
{
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> sortedArr = sortByBits(arr);
    cout << "Sorted array by number of 1 bits: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}