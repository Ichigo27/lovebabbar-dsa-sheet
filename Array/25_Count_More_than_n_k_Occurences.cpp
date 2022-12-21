// 25 Given an array of size n and a number k, fin all elements that appear more than " n/k " times.

// Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

#include <bits/stdc++.h>
using namespace std;

// Using Hashing
// Time Complexity: O(N),
// Auxiliary Space: O(N),
// int countOccurence(int arr[], int n, int k)
// {
//     int ans = 0;
//     int maxi = INT_MIN;
//     int times = n / k;
//     int hsh[100005] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, arr[i]);
//         hsh[arr[i]]++;
//     }
//     for (int i = 1; i <= maxi; i++)
//     {
//         if (hsh[i] > times)
//             ans++;
//     }
//     return ans;
// }

// Using Moore’s Voting Algorithm:
// Time Complexity: O(N * K), Checking for each element of the array(size N) in the candidate array of size K
// Auxiliary Space: O(K), Space required to store the candidates.
int countOccurence(int arr[], int n, int k)
{
	int ans = 0;
	int check = n / k;
	int mc = arr[0];
	unordered_map<int, pair<int, int>> counts;
	for (int i = 0; i < n; i++)
		counts[arr[i]] = {-1, 0};
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < k - 1; j++)
		{
			if (counts[j].first == arr[i])
			{
				counts[j].second++;
				break;
			}
		}

		if (j == k - 1)
		{
			int l;
			for (l = 0; l < k - 1; l++)
			{
				if (counts[l].second == 0)
				{
					counts[l].first = arr[i];
					counts[l].second++;
					break;
				}
			}
			if (l == k - 1)
				for (l = 0; l < k - 1; l++)
					counts[l].second -= 1;
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		int ac = 0;
		for (int j = 0; j < n; j++)
		{
			if (counts[i].first == arr[j])
				ac++;
		}
		if (ac > check)
			ans++;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << countOccurence(arr, n, k);
}