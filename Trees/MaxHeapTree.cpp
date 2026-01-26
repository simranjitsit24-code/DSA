#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
    public:
    vector<int> heap;
    MaxHeap(){}
    void heapifyup(int index)
    {
        while  (index>0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent]<heap[index])
            {
                swap(heap[parent],heap[index]);
                index = parent;
            }
            else break;
        }
    }
    void heapifydown(int index)
    {
        int n = heap.size();
        while (index<n)
        {
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;
            if (left<n && heap[left]>heap[largest])
            {
                swap(heap[left],heap[largest]);
                largest = left;
            }
            if (right<n && heap[right]>heap[largest])
            {
                swap(heap[right],heap[largest]);
                largest = right;
            }
            if (largest != index)
            {
                index = largest;
            }
            else break;
        }
    }
    void insert(int val)
    {
        heap.push_back(val);
        heapifyup(heap.size()-1);
    }
    int getMax()
    {
        if (heap.size()==0) return -1;
        int maxVal = heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        heapifydown(0);
        return maxVal;
        
    }

};
int main()
{
    MaxHeap mh;
    mh.insert(10);
    mh.insert(20);
    mh.insert(5);
    mh.insert(30);
    cout<<mh.getMax()<<endl; 
    cout<<mh.getMax()<<endl; 
    return 0;
}