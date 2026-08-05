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

// Tortoise Hare method
ListNode *middleOfLinkedList(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}

ListNode *findStartingPoint(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int findLengthOfLoop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            fast = fast->next;
            int count = 1;
            while (fast != slow)
            {
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
}

ListNode *reverseLinkedList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *newHead = reverseLinkedList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != nullptr) // if the LL is odd length then skip middle node
        slow = slow->next;
    ListNode *newHead = reverseLinkedList(slow);

    ListNode *first = head;
    ListNode *second = newHead;
    while (second != nullptr)
    {
        if (first->data != second->data)
        {
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}

ListNode *oddEvenList(ListNode *&head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *temp = head;
    int len = 1;
    while (temp->next != nullptr)
    {
        len++;
        temp = temp->next;
    }

    ListNode *remove = head;
    int count = len - n;

    if (count == 0)
    {
        ListNode *node = head;
        head = head->next;
        delete node;
        return head;
    }

    while (count > 1 && remove->next != nullptr)
    {
        remove = remove->next;
        count--;
    }
    ListNode *removeNode = remove->next;
    remove->next = remove->next->next;
    delete (removeNode);
    return head;
}
ListNode *deleteMiddle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode *temp = head;
    int len = 1;
    while (temp->next != nullptr)
    {
        len++;
        temp = temp->next;
    }

    ListNode *remove = head;
    int count = (len / 2);

    while (count > 1 && remove->next != nullptr)
    {
        remove = remove->next;
        count--;
    }
    ListNode *removeNode = remove->next;
    remove->next = remove->next->next;
    delete (removeNode);
    return head;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;
    return dummyNode->next;
}

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *middle = findMiddle(head);
    ListNode *right = middle->next;
    middle->next = nullptr;
    ListNode *left = head;

    left = sortList(left);
    right = sortList(right);
    return mergeTwoLists(left, right);
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
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(3);
    ListNode *third = new ListNode(2);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    // fifth->next = third;
    printList(head);
    head = sortList(head);
    printList(head);
    cout << endl;
}