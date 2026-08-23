#include <bits/stdc++.h>
using namespace std;

class ArrayStack
{
private:
    int *stackArray;
    int capacity;
    int topIndex;

public:
    ArrayStack(int size = 1000)
    {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1;
    }
    // Destructor
    ~ArrayStack()
    {
        delete[] stackArray;
    }
    // Pushes element x
    void push(int x)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    // Removes and returns top element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1;
        }
        return stackArray[topIndex--];
    }
    // Returns top element
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }
    /* Returns true if the stack is empty, false otherwise*/
    bool isEmpty()
    {
        return topIndex == -1;
    }
};

class ArrayQueue
{
private:
    int *queueArray;
    int capacity;
    int start;
    int end;
    int size;

public:
    ArrayQueue(int s = 1000)
    {
        capacity = s;
        queueArray = new int[capacity];
        start = -1;
        end = -1;
        size = 0;
    }

    void push(int x)
    {
        if (size == capacity)
        {
            cout << "queue is full" << endl;
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % capacity;
        }
        queueArray[end] = x;
        size++;
    }

    int pop()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        int popped = queueArray[start];
        if (size == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % capacity;
        }
        size--;
        return popped;
    }

    int peek()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return queueArray[start];
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

class QueueStack
{
    queue<int> q;

public:
    QueueStack()
    {
    }

    void push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};

class StackQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    StackQueue()
    {
    }

    void push(int x)
    {
        if (s2.empty())
        {
            s2.push(x);
        }
        else
        {
            while (!s2.empty())
            {
                int f = s2.top();
                s1.push(f);
                s2.pop();
            }
            s2.push(x);
            while (!s1.empty())
            {
                int f = s1.top();
                s2.push(f);
                s1.pop();
            }
        }
    }

    int pop()
    {
        if (s2.empty())
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        else
        {
            int f = s2.top();
            s2.pop();
            return f;
        }
    }

    int peek()
    {
        if (s2.empty())
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        else
        {
            int f = s2.top();
            return f;
        }
    }

    bool isEmpty()
    {
        if (s2.empty())
            return true;
        return false;
    }
};

struct Node
{
    int val;
    Node *next;
    Node(int d)
    {
        val = d;
        next = NULL;
    }
};
class LinkedListStack
{
    Node *head;
    int size;

public:
    LinkedListStack()
    {
        head = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node *node = new Node(x);
        node->next = head;
        head = node;
        size++;
    }

    int pop()
    {
        if (head == NULL)
            return -1;

        int value = head->val;
        Node *temp = head;
        head = head->next;
        delete (temp);
        size--;
        return value;
    }

    int top()
    {
        if (head == NULL)
            return -1;

        return head->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

class LinkedListQueue
{
    Node *start;
    Node *end;
    int size;

public:
    LinkedListQueue()
    {
        start = NULL;
        end = NULL;
        size = 0;
    }

    void push(int x)
    {
        Node *node = new Node(x);
        if (start == NULL)
            start = end = node;
        else
        {
            end->next = node;
            end = node;
        }
        size++;
    }

    int pop()
    {
        if (start == NULL)
            return -1;
        Node *node = start;
        start = start->next;
        int val = node->val;
        delete (node);
        size--;
        return val;
    }

    int peek()
    {
        if (start == NULL)
            return -1;
        return start->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

bool isValid(string str)
{
    stack<char> st;
    for (auto c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return 0;
            if ((c == ')' && st.top() == '(') ||
                (c == '}' && st.top() == '{') ||
                (c == ']' && st.top() == '['))
            {
                st.pop();
            }
            else
            {
                return 0;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "[()]";
    cout << isValid(s) << endl;
}