// 405 Find the first circular tour that visits all Petrol Pumps

// Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
// 1. The amount of petrol that every petrol pump has.
// 2. Distance from that petrol pump to the next petrol pump.
// Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
// Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

// https://youtu.be/_gJ3to4RyeQ?t=2475

int tour(petrolPump p[], int n)
{
    int need = 0;
    int remaining = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        remaining += p[i].petrol - p[i].distance;
        if (remaining < 0)
        {
            need += remaining;
            start = i + 1;
            remaining = 0;
        }
    }
    if (need + remaining >= 0)
        return start;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    petrolPump p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i].petrol >> p[i].distance;
    cout << tour(p, n) << endl;
}