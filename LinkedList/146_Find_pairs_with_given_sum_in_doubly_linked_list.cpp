// 146 Find pairs with a given sum in a DLL.

// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> res;
    if (head == NULL || head->next == NULL)
        return res;
    Node *left = head, *right = head;
    int i = 0, j = 0;
    while (right->next != NULL)
    {
        j++;
        right = right->next;
    }
    while (i < j)
    {
        if (left->data + right->data < target)
        {
            left = left->next;
            i++;
        }
        else if (left->data + right->data > target)
        {
            right = right->prev;
            j--;
        }
        else
        {
            res.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
            i++;
            j--;
        }
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
    vector<pair<int, int>> ans = findPairsWithGivenSum(head, k);
    for (auto &ele : ans)
        cout << ele.first << ' ' << ele.second << endl;
}