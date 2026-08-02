#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

ListNode *insertAtHead(ListNode *&head, int X)
{
    ListNode *node = new ListNode(X, head);
    return node;
}

ListNode *deleteHead(ListNode *&head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *node = head->next;
    delete (head);
    head = node;
    return head;
}

int getLength(ListNode *head)
{
    if (head == nullptr)
        return 0;
    ListNode *node = head;
    int len = 1;
    while (node->next != nullptr)
    {
        len++;
        node = node->next;
    }
    return len;
}

bool searchKey(ListNode *head, int key)
{
    ListNode *node = head;
    while (node->next != nullptr)
    {
        if (node->data == key)
        {
            return true;
        }
        node = node->next;
    }
    return false;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    // Creating a sample linked list: 2 -> 3
    ListNode *head = new ListNode(2);
    head->next = new ListNode(3);

    head = insertAtHead(head, 5);
    head = insertAtHead(head, 6);
    // head = deleteHead(head);

    cout << "After Insertion at Head: ";
    printList(head);
    cout << searchKey(head, 8) << endl;

    return 0;
}