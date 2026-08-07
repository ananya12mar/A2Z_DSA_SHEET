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

ListNode *deleteAllOccurrences(ListNode *head, int target)
{
    ListNode *temp = head;
    ListNode *nextNode;
    ListNode *prevNode;
    while (temp != nullptr)
    {
        if (temp->data == target)
        {
            if (temp == head)
                head = head->next;

            nextNode = temp->next;
            prevNode = temp->prev;

            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;
            delete (temp);
            temp = nextNode;
        }
        else
            temp = temp->next;
    }
    return head;
}

vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
{
    vector<vector<int>> ans;
    if (head == nullptr)
        return ans;

    ListNode *left = head;
    ListNode *right = head;

    while (right->next != nullptr)
    {
        right = right->next;
    }

    while (left->data < right->data)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
}

ListNode *removeDuplicates(ListNode *head)
{
    ListNode *temp = head;
    ListNode *nextNode;
    while (temp != nullptr && temp->next != nullptr)
    {
        nextNode = temp->next;
        while (nextNode != nullptr && nextNode->data == temp->data)
        {
            ListNode *duplicate = nextNode;
            nextNode = nextNode->next;
            delete (duplicate);
        }
        temp->next = nextNode;
        if (nextNode)
            nextNode->prev = temp;
        temp = temp->next;
    }
    return head;
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
    ListNode *head = new ListNode(4);
    head = insertBeforeHead(head, 4);
    head = insertBeforeHead(head, 1);
    head = insertBeforeHead(head, 1);
    printDLL(head);

    // vector<vector<int>> ans = findPairsWithGivenSum(head, 4);
    // for (auto v : ans)
    // {
    //     cout << v[0] << " " << v[1] << endl;
    // }

    head = removeDuplicates(head);
    printDLL(head);
    // printDLLbackwards(head);
}