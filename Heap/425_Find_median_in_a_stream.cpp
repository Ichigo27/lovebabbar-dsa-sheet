// 425 Median in a stream of Integers

// Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/RrxpTWqj97A?t=1897

class Heap
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median = 0.0;

    int signum(int a, int b)
    {
        if (a < b)
            return -1;
        else if (a == b)
            return 0;
        else
            return 1;
    }
    // Function to insert heap.
    void insertHeap(int &x)
    {
        switch (signum(maxHeap.size(), minHeap.size()))
        {
        case -1:
            if (x < median)
            {
                maxHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            break;
        case 0:
            if (x < median)
            {
                maxHeap.push(x);
                median = maxHeap.top();
            }
            else
            {
                minHeap.push(x);
                median = minHeap.top();
            }
            break;
        case 1:
            if (x < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else
            {
                minHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            break;
        }
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
    }

    // Function to return Median.
    double getMedian()
    {
        return median;
    }
};

int main()
{
    int n, x;
    Heap *hp = new Heap();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        hp->insertHeap(x);
        cout << floor(hp->getMedian()) << endl;
    }
}