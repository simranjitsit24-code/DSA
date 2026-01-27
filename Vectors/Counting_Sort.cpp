#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int>& arr,int k)
{
    vector<int> freq(k+1,0);
    for (int i=0;i<arr.size();i++)
    {
        freq[arr[i]]++;
    }
    int index =0;
    for (int i=0;i<=k;i++)
    {
        while (freq[i]>0)
        {
            arr[index]=i;
            index++;
            freq[i]--;
        }
    }
}
int main()
{
    vector<int> arr = {4,2,2,8,3,3,1};
    int k = 8; 
    countingSort(arr,k);
    cout << "Sorted array: ";
    for (int i=0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}