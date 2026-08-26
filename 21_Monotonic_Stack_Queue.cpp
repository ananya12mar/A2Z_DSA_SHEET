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

int trap(vector<int> &height)
{
    // Brute force or suboptimal solution
    //  space complexity-> O(n)
    int n = height.size();
    vector<int> suffixMax(n);
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }
    int total = 0;
    int currmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currmax = max(height[i], currmax);
        total += min(currmax, suffixMax[i]) - height[i];
    }
    return total;
}

int rain_trap(vector<int> &height)
{
    // optimised solution SC-> O(1), TC-> O(N)
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0, total = 0;
    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (leftMax > height[left])
                total += leftMax - height[left];
            else
                leftMax = height[left];
            left++;
        }
        else
        {
            if (rightMax > height[right])
                total += rightMax - height[right];
            else
                rightMax = height[right];
            right--;
        }
    }
    return total;
}

vector<int> findPSE(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();
    stack<int> st;
    for (int i = 0; i <= n - 1; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(st.top());
        st.push(i);
    }
    return res;
}

vector<int> findNSE(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (st.empty())
            res.push_back(n);
        else
            res.push_back(st.top());
        st.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int sumSubarrayMins(vector<int> &arr)
{
    vector<int> ps = findPSE(arr);
    vector<int> ns = findNSE(arr);

    int sum = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - ps[i];
        int right = ns[i] - i;
        long long freq = left * right * 1LL;
        int val = (freq * arr[i] * 1LL) % mod;
        sum = (sum + val) % mod;
    }
    return sum;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> ans;
    vector<int> st;
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (asteroids[i] > 0)
        {
            st.push_back(asteroids[i]);
        }
        else
        {
            while (!st.empty() && st.back() > 0 &&
                   st.back() < abs(asteroids[i]))
            {
                st.pop_back();
            }
            if (!st.empty() &&
                st.back() == abs(asteroids[i]))
            {
                st.pop_back();
            }
            else if (st.empty() ||
                     st.back() < 0)
            {
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
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

vector<int> findNGE(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        if (st.empty())
            res.push_back(n);
        else
            res.push_back(st.top());
        st.push(i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int sumSubarrayMax(vector<int> &arr)
{
    vector<int> ps = findPGE(arr);
    vector<int> ns = findNGE(arr);

    int sum = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - ps[i];
        int right = ns[i] - i;
        long long freq = left * right * 1LL;
        int val = (freq * arr[i] * 1LL) % mod;
        sum = (sum + val) % mod;
    }
    return sum;
}
long long subArrayRanges(vector<int> &nums)
{
    int sumGreatest = sumSubarrayMax(nums);
    int sumSmallest = sumSubarrayMins(nums);
    return sumGreatest - sumSmallest;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    cout << subArrayRanges(v1);

    // vector<int> a = {4, 2, 0, 3, 2, 5};
    // cout << rain_trap(a) << endl;
    // vector<int> ans = count_NGE(v1, v2);
    // for (auto c : ans)
    // {
    //     cout << c << " ";
    // }
}