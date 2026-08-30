#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    deque<int> dq;
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        // if the index has gone out of the window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // if the back element is lesser than current element then remove back element
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        // enter the element in the dequeue
        dq.push_back(i);

        // if current element is greater than k-1
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}

vector<int> findPGE(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i <= n - 1; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(st.top());
        st.push(i);
    }
    return res;
}

vector<int> stockSpan(vector<int> arr, int n)
{
    vector<int> PGE = findPGE(arr);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = i - PGE[i];
    }
    return ans;
}

int celebrity(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();
    int top = 0;
    int down = n - 1;

    while (top < down)
    {
        if (M[top][down] == 1)
            top++;
        else if (M[down][top] == 1)
            down--;
        else
        {
            top++;
            down--;
        }
    }
    if (top > down)
        return -1;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i == top)
                continue;
            if (M[top][i] == 0 && M[i][top] == 1)
                continue;
            else
                return -1;
        }
    }
    return top;
}

// Very Very Imp
class LRUCache
{
public:
    // Doubly linked list node class
    class Node
    {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    // Head and tail dummy nodes
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    // Capacity of cache
    int cap;
    // Hash map to store key-node mapping
    unordered_map<int, Node *> m;

    // Constructor to initialize LRU cache
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add a node right after head
    void addNodeAfterHead(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Function to remove a given node from list
    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Function to get value from cache
    int get(int key_)
    {
        // If key exists in cache
        if (m.find(key_) != m.end())
        {
            Node *resNode = m[key_];
            int res = resNode->val;
            // Remove old mapping
            m.erase(key_);
            // Move accessed node to front
            deleteNode(resNode);
            addNodeAfterHead(resNode);
            // Update map
            m[key_] = head->next;
            return res;
        }
        // If not found
        return -1;
    }

    // Function to put key-value into cache
    void put(int key_, int value)
    {
        // If key already exists
        if (m.find(key_) != m.end())
        {
            Node *existingNode = m[key_];
            m.erase(key_);
            deleteNode(existingNode);
        }
        // If capacity reached
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // Insert new node at front
        addNodeAfterHead(new Node(key_, value));
        m[key_] = head->next;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> ans = maxSlidingWindow(v, k);
    for (auto a : ans)
        cout << a << " ";
}