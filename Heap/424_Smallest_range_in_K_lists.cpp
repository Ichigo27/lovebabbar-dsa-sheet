// 424 Smallest range in “K” Lists

// Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

#include <bits/stdc++.h>
using namespace std;
#define N 1000

// https://youtu.be/RrxpTWqj97A

class Node
{
public:
    int row;
    int col;
    int data;
    Node(int row, int col, int data)
    {
        this->row = row;
        this->col = col;
        this->data = data;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
{
    int mini = INT_MAX, maxi = INT_MIN;
    int range = INT_MAX;
    priority_queue<Node *, vector<Node *>, Compare> minHeap;
    for (int i = 0; i < k; i++)
    {
        minHeap.push(new Node(i, 0, KSortedArray[i][0]));
        mini = min(mini, KSortedArray[i][0]);
        maxi = max(maxi, KSortedArray[i][0]);
    }
    int start = mini, end = maxi;
    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, KSortedArray[temp->row][temp->col + 1]);
            minHeap.push(new Node(temp->row, temp->col + 1, KSortedArray[temp->row][temp->col + 1]));
        }
        else
        {
            break;
        }
    }
    return {start, end};
}

int main()
{
    int n, k;
    cin >> n >> k;
    int KSortedArray[k][N];
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j)
            cin >> KSortedArray[i][j];
    pair<int, int> range = findSmallestRange(KSortedArray, n, k);
    cout << range.first << " " << range.second << endl;
}