// 46 Common elements in all rows of a given matrix

// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

#include <bits/stdc++.h>
using namespace std;

// A simple solution is to consider every element and check if it is present in all rows. If present, then print it. 

// A better solution is to sort all rows in the matrix and use similar approach as discussed here. Sorting will take O(mnlogn) time and finding common elements will take O(mn) time. So overall time complexity of this solution is O(mnlogn)

// Can we do better than O(mnlogn)? 
// The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in remaining rows, we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has appeared m-1 times before. 

// The time complexity of this solution is O(m * n) and we are doing only one traversal of the matrix.
// Auxiliary Space: O(N)

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[mat[0][i]] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] = i + 1;
                if (i == m - 1 && mp[mat[i][j]] == m)
                {
                    ans.push_back(mat[i][j]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<int> ans = findCommonElements(arr);
    for (auto ele : ans)
        cout << ele << ' ';
}