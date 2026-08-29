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