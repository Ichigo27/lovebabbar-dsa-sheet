// 187 DIEHARD -DIE HARD

// The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.
// If you step into air, your health increases by 3 and your armor increases by 2
// If you step into water, your health decreases by 5 and your armor decreases by 10
// If you step into fire, your health decreases by 20 and your armor increases by 5
// If your health or armor becomes <=0, you will die instantly
// Find the maximum time you can survive.

// Input:
// The first line consists of an integer t, the number of test cases. For each test case there will be two positive integers representing the initial health H and initial armor A.

// Output:
// For each test case find the maximum time you can survive.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, a;
        cin >> h >> a;
        int place = 0, res = 0;
        while (h > 0 && a > 0)
        {
            if (place == 0)
            {
                h += 3;
                a += 2;
            }
            else if (place == 1)
            {
                h -= 5;
                a -= 10;
            }
            else
            {
                h -= 20;
                a += 5;
            }

            if(h <= 0 || a <= 0)
                break;

            res++;
            if (place != 0)
            {
                place = 0;
            }
            else
            {
                double c1 = min(h / 5.0, a / 10.0);
                double c2 = h / 20.0;
                if (c1 > 1 && c1 > c2)
                {
                    place = 1;
                }
                else
                {
                    place = 2;
                }
            }
        }
        cout << res << endl;
    }
}