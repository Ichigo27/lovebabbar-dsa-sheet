// 151 Can we reverse a linked list in less than O(n) ?

// https://www.codingninjas.com/codestudio/library/is-it-possible-to-reverse-a-linked-list-in-less-than-o-n

// Linked list operations usually require reversing them, and working with single and double linked lists in programs usually needs the least time possible for operations. Hence the question here is: Can we reverse a linked list in less than O(n) time?

// Singly-linked list
// A singly linked list can be reversed using iteration and recursion, but the least possible time doing that is O(n). Every node in the linked list will be visited once to reverse it, even if we transverse the list only once. For example, for the above shown linked list to be reversed, all nodes—starting from 19 to 52, 23 and 12, respectively—will be visited when we navigate through the list. Recursion and iteration will take linear time, meaning the order will not go any lower than O(n) in either of the methods used to reverse-using extra space or simply modify and reverse the pointers.

// Doubly linked list
// If we traverse such a linked list from the pointer to the node, that will be the reverse order of the linked list. Hence for doubly-linked lists, we can swap the head and tail pointers, which takes constant time. Now, this process will take O(1) time, but to traverse in the forward direction, we will need to use the prev pointer, and to move in the reverse direction, we will need the next pointer. This is bound to cause a lot of confusion and may not be valid.

// we cannot reverse a linked list in less than O(n) time.