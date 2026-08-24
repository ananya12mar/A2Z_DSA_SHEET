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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    vector<int> ans = nextGreaterElement(v1, v2);
    for (auto c : ans)
    {
        cout << c << " ";
    }
}