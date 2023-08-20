// 446 Calculate square of a number without using *, / and pow()

// Given an integer ‘N’, you are supposed to return the square of the given integer without using multiplication (*), division (/) or power function (pow()).

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Rzra9HLoe0Q

int calculateSquare(int num)
{
    if (num == 0)
        return 0;
    if (num < 0)
        num = -num;
    int x = num >> 1;
    if (num & 1)
        return ((calculateSquare(x) << 2) + (x << 2) + 1);
    else
        return (calculateSquare(x) << 2);
}

int main()
{
    int N;
    cin >> N;
    cout << calculateSquare(N) << endl;
}