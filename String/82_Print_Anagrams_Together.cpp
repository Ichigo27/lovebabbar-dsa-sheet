// 82 Given a sequence of words, print all anagrams together

// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n * m(log m)),  where m is the length of a word.
// A single traversal through the array is needed.
// Space Complexity: O(n).
// There are n words in a string. The map requires O(n) space to store the strings.
vector<vector<string>> Anagrams(vector<string> &string_list)
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> umap;

    for (int i = 0; i < string_list.size(); i++)
    {
        string s = string_list[i];
        sort(s.begin(), s.end());
        umap[s].push_back(string_list[i]);
    }
    for (auto &itr: umap)
        result.push_back(itr.second);
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> list(n);
    for (int i = 0; i < n; i++)
        cin >> list[i];
    vector<vector<string>> ans = Anagrams(list);
    for (auto &ele : ans)
    {
        for (auto &s : ele)
        {
            cout << s << ' ';
        }
        cout << endl;
    }
}