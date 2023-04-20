// 167 Greedy Algorithm to find Minimum number of Coins

// You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=NhnsINajZRA
// Time Complexity: O(|A|) length of the string A
// Auxiliary Space: O(1)
string chooseandswap(string a)
{
    set<char> s;
    for (int i = 0; i < a.size(); i++)
        s.insert(a[i]);
    for (int i = 0; i < a.size(); i++)
    {
        s.erase(a[i]);
        if(s.empty())
            break;
        char smallest = *s.begin();
        if(smallest < a[i])
        {
            char target = a[i];
            for (int j = 0; j < a.size(); j++)
            {
                if(a[j] == smallest)
                    a[j] = target;
                else if(a[j] == target)
                    a[j] = smallest;
            }
            break;
        }
    }
    return a;
}

int main()
{
    string s;
    cin >> s;
    cout << chooseandswap(s);
}