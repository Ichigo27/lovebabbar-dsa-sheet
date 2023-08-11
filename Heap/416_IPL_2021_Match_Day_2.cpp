// 416 Maximum of all subarrays of size k.

// Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

// Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=xFJXtB5vSmM

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    vector<int> res;
    if (k > n)
    {
        res.push_back(*max_element(arr.begin(), arr.end()));
        return res;
    }
    deque<int> maxElements;
    int i = 0, j = 0;
    while (j < n)
    {
        while (!maxElements.empty() && arr[j] > maxElements.back())
            maxElements.pop_back();
        maxElements.push_back(arr[j]);
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            res.push_back(maxElements.front());
            if (maxElements.front() == arr[i])
                maxElements.pop_front();
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<int> res = max_of_subarrays(arr, n, k);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
}