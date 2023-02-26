// 86 Function to find Number of customers who could not get a computer

// Write a function “runCustomerSimulation” that takes following two inputs

//     An integer ‘n’: total number of computers in a cafe and a string:
//     A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.

// A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
// Customers who leave without using a computer always depart before customers who are currently using the computers.

#include <bits/stdc++.h>
using namespace std;

// Time complexity of above solution is O(n) and extra space required is O(CHAR_MAX) where CHAR_MAX is total number of possible characters in given sequence.
int runCustomerSimulation(int n, string seq)
{
    vector<int> check(26, 0);
    int curr = 0, res = 0;
    for (int i = 0; i < seq.size(); i++)
    {
        int c = seq[i] - 'A';
        if (check[c] == 0)
        {
            check[c] = 1;
            if (curr < n)
            {
                check[c] = 2;
                curr++;
            }
            else
            {
                res++;
            }
        }
        else
        {
            if (check[c] == 2)
            {
                check[c] = 0;
                curr--;
            }
        }
    }
    return res;
}

int main()
{
    int comp;
    cin >> comp;
    string cust;
    cin >> cust;
    cout << runCustomerSimulation(comp, cust);
}