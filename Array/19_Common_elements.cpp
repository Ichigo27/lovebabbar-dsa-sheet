// 19 find common elements In 3 sorted arrays

// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Map
//  The idea is to use hash set. Here we use 2 of the sets to store elements of the 1st and 2nd arrays. The elements of the 3rd array are then checked if they are present in the first 2 sets. Then, we use a 3rd set to prevent any duplicates from getting added to the required array.
// Time complexity: O(n1+n2+n3)
// Space complexity: O(n1+n2+n3)

// Approach 2: Binary Search
//  This approach is a modification of previous approach. Here Instead of using map, we use binary search to find elements of 1st array that are present in 2nd and 3rd arrays.
// Time complexity: O(n1(log(n2*n3))
// Space complexity: O(1)

// Approach 3: One Pass
//  we need to iterate over all three arrays in a single pass and keep track of prev to eliminate duplicates.
// https://www.youtube.com/watch?v=ajWCEu1razQ
// Time complexity: O(n1+n2+n3)
// Space complexity: O(1)

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> ans;
    int temp;
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            temp = A[i];
            ans.push_back(temp);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;
        while(A[i] == temp)
            i++;
        while (B[j] == temp)
            j++;
        while (C[k] == temp)
            k++;
    }
    return ans;
}

int main()
{
    int n1, n2, n3;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    cin >> n3;
    int arr3[n3];
    for (int i = 0; i < n3; i++)
    {
        cin >> arr3[i];
    }
    vector<int> ans = commonElements(arr1, arr2, arr3, n1, n2, n3);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
}