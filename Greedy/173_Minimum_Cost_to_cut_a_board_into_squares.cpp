// 173 Minimum Cost to cut a board into squares

// A board of length M and width N is given. The task is to break this board into M * N squares such that cost of breaking is minimum. The cutting cost for each edge will be given for the board in two arrays X[] and Y[]. In short, you need to choose such a sequence of cutting such that cost is minimized. Return the minimized cost.

#include <bits/stdc++.h>
using namespace std;

// Time complexity : As we have to sort the array of length M and N , the time complexity is O(NlogN + MlogM).
// space complexity : As we are not using any extra auxiliary space . So the space complexity will be O(1).
int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N)
{
    int cost = 0;
    int Xpiece = 1, Ypiece = 1;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int i = M - 2, j = N - 2;
    while (i >= 0 && j >= 0)
    {

        if (X[i] > Y[j])
        {
            cost += X[i] * Xpiece;
            Ypiece++;
            i--;
        }
        else
        {
            cost += Y[j] * Ypiece;
            Xpiece++;
            j--;
        }
    }
    while (i >= 0)
    {
        cost += X[i] * Xpiece;
        Ypiece++;
        i--;
    }
    while (j >= 0)
    {
        cost += Y[j] * Ypiece;
        Xpiece++;
        j--;
    }
    return cost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n - 1), y(m - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> x[i];
    for (int i = 0; i < m - 1; i++)
        cin >> y[i];
    cout << minimumCostOfBreaking(x, y, n, m);
}