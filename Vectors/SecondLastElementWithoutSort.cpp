#include <bits/stdc++.h>
using namespace std;
#define max 1000
int main()
{
 int arr[max];
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
 for (int i=0;i<n;i++)
 {

    for (int j=0;j<n-i;j++)
    {
        if (arr[i]<arr[j])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    if (i==1)
    {
        break;
    }
 }
 cout<<"The Second Largest Element in the array is: "<<arr[n-2];
}