// 227 word Ladder

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//     Every adjacent pair of words differs by a single letter.
//     Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//     sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2 * M^2) where N is the number of words and M is the length of the word

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int flag = 0;
    for (int i = 0; i < wordList.size(); i++)
    {
        if (wordList[i] == endWord)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return 0;

    unordered_map<string, vector<string>> adjList;
    wordList.push_back(beginWord);
    for (int i = 0; i < wordList.size(); i++)
    {
        for (int j = 0; j < wordList[i].size(); j++)
        {
            string key = wordList[i];
            key[j] = '*';
            adjList[key].push_back(wordList[i]);
        }
    }

    unordered_set<string> s;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    s.insert(beginWord);
    while (!q.empty())
    {
        string curr = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (curr == endWord)
        {
            return cost;
        }
        for (int i = 0; i < curr.size(); i++)
        {
            string temp = curr;
            temp[i] = '*';
            for (auto &word : adjList[temp])
            {
                if (s.find(word) == s.end())
                {
                    q.push({word, cost + 1});
                    s.insert(word);
                }
            }
        }
    }
    return 0;
}

int main()
{
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++)
        cin >> wordList[i];
    cout << ladderLength(beginWord, endWord, wordList);
}
