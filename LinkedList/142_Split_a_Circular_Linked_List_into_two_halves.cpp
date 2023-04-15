// 142 Split a Circular linked list into two halves.

// Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (head == NULL || head->next == NULL)
        return;
    Node *curr = head;
    int i = 1;
    while (curr->next != head)
    {
        i++;
        curr = curr->next;
    }
    curr = head;
    Node *head1 = new Node(-1), *tail1 = head1;
    int j = 0;
    while (j < (i + 1) / 2)
    {
        tail1->next = new Node(curr->data);
        tail1 = tail1->next;
        curr = curr->next;
        j++;
    }
    tail1->next = head1->next;
    Node *head2 = new Node(-1), *tail2 = head2;
    while (j < i)
    {
        tail2->next = new Node(curr->data);
        tail2 = tail2->next;
        curr = curr->next;
        j++;
    }
    tail2->next = head2->next;
    *head1_ref = head1->next;
    *head2_ref = head2->next;
}

// gfg
// void splitList(Node *head, Node **head1_ref,
//                Node **head2_ref)
// {
//     Node *slow_ptr = head;
//     Node *fast_ptr = head;

//     if (head == NULL)
//         return;

//     /* If there are odd nodes in the circular list then
//        fast_ptr->next becomes head and for even nodes
//        fast_ptr->next->next becomes head */
//     while (fast_ptr->next != head &&
//            fast_ptr->next->next != head)
//     {
//         fast_ptr = fast_ptr->next->next;
//         slow_ptr = slow_ptr->next;
//     }

//     /* If there are even elements in list
//        then move fast_ptr */
//     if (fast_ptr->next->next == head)
//         fast_ptr = fast_ptr->next;

//     /* Set the head pointer of first half */
//     *head1_ref = head;

//     /* Set the head pointer of second half */
//     if (head->next != head)
//         *head2_ref = slow_ptr->next;

//     /* Make second half circular */
//     fast_ptr->next = slow_ptr->next;

//     /* Make first half circular */
//     slow_ptr->next = head;
// }

int main()
{
    int n;
    cin >> n;
    Node *head = NULL, *tail = NULL;
    int first;
    cin >> first;
    head = new Node(first);
    tail = head;
    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        tail->next = new Node(num);
        tail = tail->next;
    }
    tail->next = head;
    Node *head1 = NULL, *head2 = NULL;
    splitList(head, &head1, &head2);
    printlist(head1);
    cout << endl;
    printlist(head2);
}