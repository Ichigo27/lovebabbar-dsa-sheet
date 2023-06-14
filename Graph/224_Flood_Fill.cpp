// 224 flood fill algo

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(V + E)
// Space complexity: O(V)

void dfs(int i, int j, int start, int color, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != start)
        return;
    image[i][j] = color;
    dfs(i + 1, j, start, color, image);
    dfs(i, j + 1, start, color, image);
    dfs(i - 1, j, start, color, image);
    dfs(i, j - 1, start, color, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int start = image[sr][sc];
    if (start != color)
        dfs(sr, sc, start, color, image);
    return image;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> image[i][j];
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}