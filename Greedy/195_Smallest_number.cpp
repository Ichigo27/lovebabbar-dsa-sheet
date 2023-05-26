// 195 Find smallest number with given number of digits and sum of digits

// The task is to find the smallest number with given sum of digits as S and number of digits as D.

#include <bits/stdc++.h>
using namespace std;

// int sumDigit(int n)
// {
//     int res = 0;
//     while (n > 0)
//     {
//         res += n % 10;
//         n = n / 10;
//     }
//     return res;
// }

// string smallestNumber(int S, int D)
// {
//     if(S == 0 && D == 1)
//         return "0";
//     int low = pow(10, D - 1);
//     int high = pow(10, D);
//     for (int i = low; i < high; i++)
//     {
//         if(sumDigit(i) == S)
//             return to_string(i);
//     }
//     return "-1";
// }

string smallestNumber(int S, int D)
{
    if (S == 0)
    {
        if (D == 1)
            return "0";
        else
            return "-1";
    }
    else if (9 * D < S)
    {
        return "-1";
    }

    int res[D];
    string ans = "";
    S -= 1;
    for (int i = D - 1; i > 0; i--)
    {
        if (S > 9)
        {
            res[i] = 9;
            S -= 9;
        }
        else
        {
            res[i] = S;
            S = 0;
        }
    }
    res[0] = S + 1;
    for (int i = 0; i < D; i++)
    {
        ans += ('0' + res[i]);
    }
    return ans;
}

int main()
{
    int s, d;
    cin >> s >> d;
    cout << smallestNumber(s, d);
}