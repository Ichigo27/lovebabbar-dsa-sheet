// 88 Check if two given strings are isomorphic to each other

// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in str1 should map to the same character in str2

#include <bits/stdc++.h>
using namespace std;

// Naive Approach:

// A Simple Solution is to consider every character of ‘str1’ and check if all occurrences of it map to the same character in ‘str2’.

// Time Complexity: O(N * N)
// Auxiliary Space: O(1)

// Optimized Approach:

// Check if two given strings are isomorphic to each other using Mapping:

//     The idea is to create an array to store mappings of processed characters.

// Check if two given strings are isomorphic to each other using Hashing:

//     The idea is to store the frequency of both strings in the separate array and then check if the frequency of the mapped characters are same or not.

// Check if two given strings are isomorphic to each other using Single Hashmap:

//     The idea is to store map the character and check whether the mapping is correct or not.

// Time Complexity: O(N), traversing over the string of size N.
// Auxiliary Space: O(1)
bool areIsomorphic(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    if (n != m)
        return false;
    unordered_map<char, char> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(str1[i]) != 0)
        {
            if(mp[str1[i]] != str2[i])
                return false;
        }
        else
        {
            vector<char> vec;
            for (auto ele : mp)
                vec.push_back(ele.second);
            if (find(vec.begin(), vec.end(), str2[i]) != vec.end())
                return false;
            mp[str1[i]] = str2[i];
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << areIsomorphic(s1, s2);
}