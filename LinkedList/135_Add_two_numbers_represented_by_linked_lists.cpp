// 135 Add two numbers represented by linked lists.

// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

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

Node *reverseLL(Node *head)
{
    Node *pre = NULL;
    Node *cur = head;
    while (cur != NULL)
    {
        Node *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{

    struct Node *head = new Node(0), *head1 = NULL, *head2 = NULL;
    struct Node *tail = head, *prev = NULL;
    first = reverseLL(first);
    head1 = first;
    second = reverseLL(second);
    head2 = second;
    while (head1->next != NULL || head2->next != NULL)
    {
        tail->next = new Node(0);
        tail = tail->next;
        if (head1->next != NULL)
            head1 = head1->next;
        if (head2->next != NULL)
            head2 = head2->next;
    };
    tail = head;
    head1 = first;
    head2 = second;
    int carry = 0, sum = 0;
    while (head1 != NULL || head2 != NULL)
    {
        int n1 = head1 == NULL ? 0 : head1->data;
        int n2 = head2 == NULL ? 0 : head2->data;
        sum = n1 + n2 + carry;
        if (sum < 10)
        {
            tail->data = sum;
            carry = 0;
        }
        else
        {
            tail->data = sum % 10;
            carry = 1;
        }
        prev = tail;
        tail = tail->next;
        if (head1 != NULL)
            head1 = head1->next;
        if (head2 != NULL)
            head2 = head2->next;
    }
    if (carry == 1)
        prev->next = new Node(1);
    head = reverseLL(head);
    return head;
}

// gfg
// struct Node *addTwoLists(struct Node *first, struct Node *second)
// {
//     // reversing both lists to simplify addition.
//     first = reverseLL(first);
//     second = reverseLL(second);

//     Node *sum = NULL;
//     int carry = 0;

//     // using a loop till both lists and carry gets exhausted.
//     while (first != NULL || second != NULL || carry != 0)
//     {
//         // using a variable to store sum of two digits along with carry.
//         int newVal = carry;

//         // if nodes are left in any list, we add their data in newVal.
//         if (first)
//             newVal += first->data;
//         if (second)
//             newVal += second->data;

//         // updating carry.
//         carry = newVal / 10;

//         // using modulus to store only a single digit at that place.
//         newVal = newVal % 10;

//         // creating new node which gets connected with other nodes that
//         // we get after calculating sum of respective digits.
//         Node *newNode = new Node(newVal);

//         // storing the previously made nodes in the link part of new node.
//         newNode->next = sum;

//         // making the new node as the first node of all previously made node.
//         sum = newNode;

//         // moving ahead in both lists.
//         if (first)
//             first = first->next;
//         if (second)
//             second = second->next;
//     }
//     return sum;
// }

int main()
{
    int n;
    cin >> n;
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
    int m;
    cin >> m;
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
    Node *head = addTwoLists(head1, head2);
    printlist(head);
}