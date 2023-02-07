// 66 Convert a Sentence into its equivalent mobile numeric keypad sequence.

// Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence. Please note there might be spaces in between the words in a sentence and we can print spaces by pressing 0.

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(Length of String)
// Auxiliary Space: O(Length of String)
string printSequence(string S)
{
    string ans = "";
    for (char let : S)
    {
        if (let == ' ')
            ans.push_back('0');
        else
        {
            int x = int(let) - int('A');
            if (x < 15)
            {
                int num = x / 3;
                int times = (x % 3) + 1;
                while (times--)
                {
                    ans.push_back(char(num + int('2')));
                }
            }
            else if (x > 14 && x < 19)
            {
                int times = ((x - 15) % 4) + 1;
                while (times--)
                {
                    ans.push_back('7');
                }
            }
            else if (x > 18 && x < 22)
            {
                int times = ((x - 19) % 3) + 1;
                while (times--)
                {
                    ans.push_back('8');
                }
            }
            else if (x > 21 && x < 26)
            {
                int times = ((x - 22) % 4) + 1;
                while (times--)
                {
                    ans.push_back('9');
                }
            }
        }
    }
    return ans;
}

// GFG code
// Time complexity: O(N), For traversing the string
// Auxiliary Space: O(N), For storing the answer.
// string printSequence(string S)
// {
//     // storing the sequence in array
//     string arr[] = {"2", "22", "222", "3", "33", "333", "4",
//                     "44", "444", "5", "55", "555", "6", "66",
//                     "666", "7", "77", "777", "7777", "8", "88",
//                     "888", "9", "99", "999", "9999"};

//     string output = "";

//     // length of S string
//     int n = S.length();
//     for (int i = 0; i < n; i++)
//     {
//         // Checking for space
//         if (S[i] == ' ')
//             output = output + "0";

//         else
//         {
//             // Calculating index for each
//             // character
//             int position = S[i] - 'A';
//             output = output + arr[position];
//         }
//     }

//     // Output sequence
//     return output;
// }

int main()
{
    string s;
    getline(cin, s);
    cout << printSequence(s);
}