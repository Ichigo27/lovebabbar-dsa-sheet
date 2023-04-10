// 127 Reverse a Linked List in group of Given Size. [Very Imp]

// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

// Time Complexity : O(N)
// Auxilliary Space : O(1)

// gfg
// node *reverse(node *head, int k)
// {
//     node *temp = new node(-1);
//     node *pre = temp;
//     node *cur = temp;
//     node *nxt = temp;
//     temp->next = head;
//     int cnt = 0;
//     while (cur->next != NULL)
//     {
//         cur = cur->next;
//         cnt++;
//     }
//     while (cnt > 0)
//     {
//         int i = k - 1;
//         cur = pre->next;
//         nxt = cur->next;
//         while (cur->next != NULL && i--)
//         {
//             cur->next = nxt->next;
//             nxt->next = pre->next;
//             pre->next = nxt;
//             nxt = cur->next;
//         }
//         pre = cur;
//         cnt -= k;
//     }
//     return temp->next;
// }

// leetcode
//https://www.youtube.com/watch?v=Of0HPkk3JgI
// ListNode *reverseKGroup(ListNode *head, int k)
// {
//     ListNode *temp = new ListNode(-1);
//     ListNode *pre = temp;
//     ListNode *cur = temp;
//     ListNode *nxt = temp;
//     temp->next = head;
//     int cnt = 0;
//     while (cur->next != NULL)
//     {
//         cur = cur->next;
//         cnt++;
//     }
//     while (cnt - k >= 0)
//     {
//         int i = k - 1;
//         cur = pre->next;
//         nxt = cur->next;
//         while (i--)
//         {
//             cur->next = nxt->next;
//             nxt->next = pre->next;
//             pre->next = nxt;
//             nxt = cur->next;
//         }
//         pre = cur;
//         cnt -= k;
//     }
//     return temp->next;
// }

// gfg
// https://youtu.be/znQ8wJxnRao
struct node *reverse(struct node *head, int k)
{
    node *pre = NULL;
    node *cur = head;
    node *nxt;
    int i = 0;
    while (cur != NULL && i < k)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
        i++;
    }
    if (nxt != NULL)
        head->next = reverse(nxt, k);
    return pre;
}

// leetcode
// ListNode *reverseKGroup(ListNode *head, int k)
// {
//     ListNode *temp = head;
//     int cnt = 0;
//     while (temp != NULL)
//     {
//         cnt++;
//         temp = temp->next;
//     }
//     if (cnt < k)
//         return head;
//     ListNode *pre = NULL;
//     ListNode *cur = head;
//     ListNode *nxt;
//     int i = 0;
//     while (cur != NULL && i < k)
//     {
//         nxt = cur->next;
//         cur->next = pre;
//         pre = cur;
//         cur = nxt;
//         i++;
//     }
//     if (nxt != NULL)
//         head->next = reverseKGroup(nxt, k);
//     return pre;
// }

int main()
{
    int n;
    cin >> n;
    node *head = NULL, *tail = NULL;
    int first;
    cin >> first;
    head = new node(first);
    tail = head;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        tail->next = new node(num);
        tail = tail->next;
    }
    int k;
    cin >> k;
    head = reverse(head, k);
    printlist(head);
}