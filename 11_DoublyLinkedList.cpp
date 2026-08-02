#include <bits/stdc++.h>
using namespace std;

class ListNode
{
    // Definition for doubly-linked list.
public:
    int data;
    ListNode *prev;
    ListNode *next;
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr), next(nullptr) {}
    ListNode(int x, ListNode *prev, ListNode *next) : data(x), prev(prev), next(next) {}
};

ListNode *insertBeforeHead(ListNode *head, int X)
{
    ListNode *node = new ListNode(X);
    if (head == nullptr)
    {
        return node;
    }
    head->prev = node;
    node->next = head;
    head = node;
    return head;
}

ListNode *deleteHead(ListNode *&head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *node = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete (node);
    return head;
}

ListNode *reverseDLL(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *tail = head;
    ListNode *tempHead = head;

    while (tail->next != nullptr)
        tail = tail->next;

    while (tail != head && tail->next != head)
    {
        int tempData = tail->data;
        tail->data = head->data;
        head->data = tempData;
        tail = tail->prev;
        head = head->next;
    }
    return tempHead;
}

void printDLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printDLLbackwards(ListNode *head)
{
    if (head == nullptr)
    {
        cout << endl;
        return;
    }

    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    while (tail != nullptr)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(2);
    head = insertBeforeHead(head, 3);
    head = insertBeforeHead(head, 4);
    head = insertBeforeHead(head, 5);

    head = deleteHead(head);
    printDLL(head);
    reverseDLL(head);
    printDLL(head);
    // printDLLbackwards(head);
}