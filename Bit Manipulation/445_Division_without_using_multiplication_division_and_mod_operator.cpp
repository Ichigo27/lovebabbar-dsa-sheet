// 445 Divide two integers without using multiplication, division and mod operator

// Given two integers dividend and divisor. Find the quotient after dividing dividend by divisor without using multiplication, division and mod operator.

#include <bits/stdc++.h>
using namespace std;

long long divide(long long dividend, long long divisor)
{
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1: 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    long long quotient = 0, temp = 0;
    for(int i = 31; i >= 0; i--)
    {
        if(temp + (divisor << i) <= dividend)
        {
            temp += divisor << i;
            quotient |= 1LL << i;
        }
    }
    return sign == 1 ? quotient : -quotient;
}

int main()
{
    long long dividend, divisor;
    cin >> dividend >> divisor;
    cout << divide(dividend, divisor);
}