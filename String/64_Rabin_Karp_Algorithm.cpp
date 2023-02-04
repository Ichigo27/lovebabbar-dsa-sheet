// 64 Rabin Karp Algo

// Given a text txt[0. . .n-1] and a pattern pat[0. . .m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity:

//     The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
//     The worst case of the Rabin-Karp algorithm occurs when all characters of pattern and text are the same as the hash values of all the substrings of txt[] match with the hash value of pat[].

// Auxiliary Space: O(1)

void search(string pat, string txt, int q)
{
    int M = pat.length();
    int N = txt.length();
    int d = 256, p = 0, t = 0, h = 1;

    for (int i = 0; i < M - 1; i++)
        h = (d * h) % q;

    for (int i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            int flag = 0;
            for (int j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Pattern Found at Index " << i << endl;
            }
        }
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if(t < 0)
                t += q;
        }
    }
}

int main()
{
    string pat, txt;
    cin >> pat >> txt;
    int num = 11;
    search(pat, txt, num);
}