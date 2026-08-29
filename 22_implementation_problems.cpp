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