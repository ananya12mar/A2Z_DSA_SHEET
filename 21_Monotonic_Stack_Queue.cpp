#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < arr[i])
            st.pop();

        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());

        st.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans = nextLargerElement(nums2);
    map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < nums2.size(); i++)
    {
        mp.insert({nums2[i], ans[i]});
    }
    for (auto a : nums1)
    {
        res.push_back(mp[a]);
    }
    return res;
}

vector<int> nextGreaterElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;
        int currEle = arr[idx];
        while (!st.empty() && st.top() <= currEle)
            st.pop();

        if (i < n)
        {
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }
        st.push(currEle);
    }
    return ans;
}

vector<int> nextSmallerElements(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() > arr[i])
            st.pop();
        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top();

        st.push(arr[i]);
    }
    return res;
}

vector<int> count_NGE(vector<int> &arr, vector<int> &indices)
{
    int N = arr.size();
    vector<int> ans(2);
    for (int j = 0; j < 2; j++)
    {
        int count = 0;
        for (int i = indices[j] + 1; i < N; i++)
        {
            if (arr[i] > arr[indices[j]])
                count++;
        }
        ans[j] = count;
    }

    return ans;
}

int main()
{
    int n, a, b;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cin >> a >> b;
    v2.push_back(a);
    v2.push_back(b);
    // for (int i = 0; i < m; i++)
    // {
    //     int x;
    //     cin >> x;
    //     v2.push_back(x);
    // }
    vector<int> ans = count_NGE(v1, v2);
    for (auto c : ans)
    {
        cout << c << " ";
    }
}