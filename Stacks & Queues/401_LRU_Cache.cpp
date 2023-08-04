// 401 LRU Cache Implementation

// Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:
//     SET x y: sets the value of the key x with value y
//     GET x: gets the key of x if present else returns -1.

// The LRUCache class has two methods get() and set() which are defined as follows.
//     get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
//     set(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
//     In the constructor of the class the capacity of the cache should be initialized.

#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=xDEuM5qa0zg&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=79
// https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=77

class LRUCache
{

private:
    class Node
    {
    public:
        int key, val;
        Node *prev, *next;
        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
            prev = next = NULL;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> mp;
    int size;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        size = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addNodeToFront(Node *curr)
    {
        Node *temp = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = temp;
        temp->prev = curr;
    }

    void deleteNode(Node *curr)
    {
        Node *tempPrev = curr->prev;
        Node *tempNext = curr->next;
        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;
    }

    // Function to return value corresponding to the key.
    int GET(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        Node *temp = mp[key];
        int value = temp->val;
        mp.erase(key);
        deleteNode(temp);
        addNodeToFront(temp);
        mp[key] = head->next;
        return value;
    }

    // Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if (mp.size() == size)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNodeToFront(new Node(key, value));
        mp[key] = head->next;
    }
};

int main()
{
    int n;
    cin >> n;
    LRUCache *cache = new LRUCache(n);
    int Q;
    cin >> Q;
    while (Q--)
    {
        string QueryType;
        cin >> QueryType;
        if (QueryType == "SET")
        {
            int key;
            cin >> key;
            int value;
            cin >> value;
            cache->SET(key, value);
        }
        else
        {
            int key;
            cin >> key;
            cout << cache->GET(key) << " ";
        }
    }
}