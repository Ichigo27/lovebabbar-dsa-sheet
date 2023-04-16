// 147 Count triplets in a sorted DLL whose sum is equal to given value “X”.

// Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void printlist(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

// Time Complexity: O(n2)
// Auxiliary Space : O(1)
vector<vector<int>> findTriplets(Node *head, int target)
{
    vector<vector<int>> res;
    if (head == NULL || head->next == NULL)
        return res;
    Node *left = head, *right = head;
    while (right->next != NULL)
    {
        right = right->next;
    }
    Node *k = head;
    while (k != NULL)
    {
        Node *l = k->next, *r = right;
        while (l != NULL && r != NULL && l != r && r->next != l)
        {
            if (l == k || l->data + r->data < target - k->data)
            {
                l = l->next;
            }
            else if (r == k || l->data + r->data > target - k->data)
            {
                r = r->prev;
            }
            else
            {
                res.push_back({k->data, l->data, r->data});
                l = l->next;
                r = r->prev;
            }
        }
        k = k->next;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    Node *head = NULL, *tail = NULL;
    int first;
    cin >> first;
    head = new Node(first);
    tail = head;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        Node *temp = new Node(num);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    vector<vector<int>> ans = findTriplets(head, k);
    cout << ans.size() << endl;
    for (auto &ele : ans)
        cout << ele[0] << ' ' << ele[1] << ' ' << ele[2] << endl;
}