// 49 Find Duplicate characters in a string

// Write an efficient program to print all the duplicates and their counts in the input string

#include <bits/stdc++.h>
using namespace std;

// Using Hashing
//
// Time Complexity: O(n), where n = length of the string passed
// Space Complexity: O(NO_OF_CHARS = 256)

// Using Map
// Time Complexity: O(N), where N = length of the string passed and it takes O(1) time to insert and access any element in an unordered map
// Auxiliary Space: O(K), where K = size of the map (0<=K<=input_string_length).
void printDups(string s)
{
    vector<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (auto ele: mp)
    {
        if(ele.second > 1)
            cout << ele.first << ' ';
    }
}

int main()
{
    string s;
    cin >> s;
    printDups(s);
}