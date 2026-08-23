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

int main()
{
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push",
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            queue.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << queue.pop() << " ";
        }
        else if (commands[i] == "peek")
        {
            cout << queue.peek() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayQueue")
        {
            cout << "null ";
        }
    }

    return 0;
}