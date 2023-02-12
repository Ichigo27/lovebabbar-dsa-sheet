// 76 Minimum number of swaps for bracket balancing.

// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
// Note - Strings S1 and S2 can be empty.

#include <bits/stdc++.h>
using namespace std;

// Naive Approach:
// Initialize sum = 0 where sum stores result. Go through the string maintaining a count of the number of ‘[‘ brackets encountered. Reduce this count when we encounter a ‘]’ character. If the count hits negative, then we must start balancing the string.
// Let index ‘i’ represents the position we are at. We now move forward to the next ‘[‘ at index j. Increase sum by j – i. Move the ‘[‘ at position j, to position i, and shift all other characters to the right. Set the count back to 0 and continue traversing the string. In the end, ‘sum’ will have the required value.

// Time Complexity = O(N2)
// Extra Space = O(1)

// Optimized approach:
// We can initially go through the string and store the positions of ‘[‘ in a vector say ‘pos‘. Initialize ‘p’ to 0. We shall use p to traverse the vector ‘pos’. Similar to the naive approach, we maintain a count of encountered ‘[‘ brackets. When we encounter a ‘[‘ we increase the count and increase ‘p’ by 1. When we encounter a ‘]’ we decrease the count. If the count ever goes negative, this means we must start swapping. The element pos[p] tells us the index of the next ‘[‘. We increase the sum by pos[p] – i, where i is the current index. We can swap the elements in the current index and pos[p] and reset the count to 0.

// Since we have converted a step that was O(N) in the naive approach, to an O(1) step, our new time complexity reduces.
// Time Complexity = O(N)
// Extra Space = O(N)

// Another More Optimised Solution:

// We can just keep a counter variable " imbalance " that checks the balance i.e. if the number of closing brackets is more than opening bracket than it would have a positive value. Whenever we come across an opening bracket  ' [ ' we would check if the " imbalance " is positive or not. If found positive that means we have to swap this bracket with the previous characters and reach the position where imbalance first becomes positive. As we are only concerned with the number of operations, it will take " imbalance " number of operations to perform the swap. Write test cases in the notebook to understand nicely.

// if swap can happen anywhere - https://www.youtube.com/watch?v=3YDBT9ZrfaU
// else 
// Time Complexity = O(N)
// Extra Space = O(1)
int minimumNumberOfSwaps(string s)
{
    // code here
    int ans = 0, error = 0, open = 0, close = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            open++;
            if(error > 0)
            {
                ans += error;
                error--;
            }
        }
        else if (s[i] == ']')
            close++;
        if(close > open)
            error = close - open;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << minimumNumberOfSwaps(s);
}