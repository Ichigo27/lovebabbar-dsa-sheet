// 121 DoubleHelix SPOJ

//  Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
// printed in bold:

//     First= 3 5 7 9 20 25 30 40 55 56 57 60 62
//     Second= 1 4 7 11 14 25 44 47 55 57 100

// You can ‘walk” over these two sequences in the following way:

//     You may start at the beginning of any of the two sequences. Now start moving forward.
//     At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.

// The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62
// Input

// Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format:

// n v1 v2 ... vn

// Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive).
// The last line of the input includes a single zero, which is not part of the test cases.
// Output

// For each test case, write on a separate line, the largest possible sum that can be produced.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int n1;
        cin >> n1;
        if (n1 == 0)
            break;
        int arr1[n1];
        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }
        int n2;
        cin >> n2;
        int arr2[n2];
        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }
        int i = 0, j = 0, s1 = 0, s2 = 0, res = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                s1 += arr1[i++];
            }
            else if (arr1[i] > arr2[j])
            {
                s2 += arr2[j++];
            }
            else
            {
                res += arr1[i] + max(s1, s2);
                s1 = 0;
                s2 = 0;
                i++;
                j++;
            }
        }
        while (i < n1)
        {
            s1 += arr1[i++];
        }
        while (j < n2)
        {
            s2 += arr2[j++];
        }
        res += max(s1, s2);
        cout << res << endl;
    }
}