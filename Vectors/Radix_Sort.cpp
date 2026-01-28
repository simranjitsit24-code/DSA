#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int>& arr,int exp)
{
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10,0);
    for (int i=0;i<n;i++)
    {
         count[(arr[i]/exp)%10]++;
    }

    for (int i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }

    for (int i=n-1;i>=0;i--)
    {
        int dig = (arr[i]/exp)%10;
        output[count[dig] - 1] = arr[i];
        count[dig]--;
    }
    arr = output;
}
void RadixSort(vector <int>& arr)
{
  int maxele = *max_element(arr.begin(),arr.end());
  for (int exp =1; maxele/exp >0;exp*=10)
  {
        countingSort(arr,exp);
  }
}
int main()
{
    vector<int> arr = {170,45,75,90,802,24,2,66};
    RadixSort(arr);
    cout << "Sorted array: ";
    for (int i=0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}