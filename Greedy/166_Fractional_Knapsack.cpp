// 166 Fractional Knapsack Problem

// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item.

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

static bool compare(Item a, Item b)
{
    double ratioA = a.value / (a.weight * 1.0);
    double ratioB = b.value / (b.weight * 1.0);
    return ratioA > ratioB;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, compare);
    double profit = 0;
    for (int i = 0; i < n; i++)
    {

        if (W >= arr[i].weight)
        {
            profit += arr[i].value;
            W -= arr[i].weight;
            if (W == 0)
                break;
        }
        else
        {
            profit += arr[i].value * (W / (arr[i].weight * 1.0));
            break;
        }
    }
    return profit;
}

int main()
{
    int n, w;
    cin >> n >> w;
    Item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }
    cout << fractionalKnapsack(w, arr, n);
}
