#include <bits/stdc++.h>
using namespace std;
// bucket sort is best when input is uniformly distributed over a range eg [0.23,0.34] 
void bucketSort(vector<float>& arr, int buckcount)
{
    vector<vector<float>> buckets(buckcount);
    for (float j:arr)
    {
        int idx = j*buckcount;
        buckets[idx].push_back(j);
    }
    for (int i=0;i<buckcount;i++)
    {
        // insertion sort for sorting individual buckets
        for (int j=1;j<buckets[i].size();j++)
        {
            float key = buckets[i][j];
            int k = j-1;
            while (k>=0 && buckets[i][k]>key)
            {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }
    int idx = 0;
    for (int i=0;i<buckcount;i++)
    {
        for (int j=0;j<buckets[i].size();j++)
        {
            arr[idx++] = buckets[i][j]; 
        }
    }
}

int main()
{
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int buckcount = 5; 
    bucketSort(arr, buckcount);
    cout << "Sorted array: ";
    for (float num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}