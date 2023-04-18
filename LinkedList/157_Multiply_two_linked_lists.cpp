// 157 Multiply 2 no. represented by LL

// Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2.

// Note: The output could be large take modulo 1e9+7.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
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

// Time Complexity: O(N).
// Auxiliary Space: O(1).
long long multiplyTwoLists(Node *l1, Node *l2)
{
    int m = 1000000007;
    long long num1 = 0, num2 = 0;
    while (l1 != NULL)
    {
        num1 = ((num1 * 10) % m + (l1->data) % m) % m;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        num2 = ((num2 * 10) % m + (l2->data) % m) % m;
        l2 = l2->next;
    }
    return (num1 * num2) % m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Node *head1 = NULL, *tail1 = NULL;
    int first1;
    cin >> first1;
    head1 = new Node(first1);
    tail1 = head1;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        tail1->next = new Node(num);
        tail1 = tail1->next;
    }
    Node *head2 = NULL, *tail2 = NULL;
    int first2;
    cin >> first2;
    head2 = new Node(first2);
    tail2 = head2;
    for (int i = 1; i < m; i++)
    {
        int num;
        cin >> num;
        tail2->next = new Node(num);
        tail2 = tail2->next;
    }
    cout << multiplyTwoLists(head1, head2);
}