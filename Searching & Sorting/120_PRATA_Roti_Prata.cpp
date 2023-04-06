// 120 ROTI-Prata SPOJ

// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

// Input

// The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

// Output

// Print an integer which tells the number of minutes needed to get the order done.

#include <bits/stdc++.h>
using namespace std;

bool is_possible(int arr[], int n, int p, int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int total = 0, mul = 1;
        while (total + arr[i] * mul <= mid)
        {
            total += arr[i] * mul;
            cnt++;
            mul++;
        }
    }
    if(cnt >= p)
        return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        int low = 0, high = INT_MAX, mid, res = 0;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (is_possible(arr, n, p, mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << res << endl;
    }
}