// 67 Minimum number of bracket reversals needed to make an expression balanced.

// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice - versa.

#include <bits/stdc++.h>
using namespace std;

// A Naive Solution is to consider every bracket and recursively count number of reversals by taking two cases (i) keeping the bracket as it is (ii) reversing the bracket. If we get a balanced expression, we update result if number of steps followed for reaching here is smaller than the minimum so far. Time complexity of this solution is O(2n).

// Efficient Solution with O(n) space
// Time Complexity: O(n)
// Auxiliary Space: O(n)
// int countRev(string s)
// {
//     if (s.size() % 2 == 1)
//         return -1;
//     int ans = 0;
//     stack<char> st;
//     for (char bracket : s)
//     {
//         if (bracket == '{')
//         {
//             st.push('{');
//         }
//         else
//         {
//             if (!st.empty() && st.top() == '{')
//                 st.pop();
//             else
//                 st.push('}');
//         }
//     }
//     while (!st.empty())
//     {
//         int temp = st.top();
//         st.pop();
//         if (temp == st.top())
//         {
//             ans += 1;
//         }
//         else
//         {
//             ans += 2;
//         }
//         st.pop();
//     }
//     return ans;
// }

// Efficient Solution with O(1) space
// Time Complexity: O(n)
// Auxiliary Space: O(1)
int countRev(string s)
{
    if (s.size() % 2 == 1)
            return -1;
    int open = 0, close = 0;
    for(char bracket: s)
    {
        if(bracket == '{')
            open++;
        else
        {
            if(open > 0)
                open--;
            else
                close++;
        }
    }
    return ceil(open / 2.0) + ceil(close / 2.0);
}


int main()
{
    string s;
    cin >> s;
    cout << countRev(s);
}