#include <bits/stdc++.h>
using namespace std;

int minBitsFlip(int start, int goal)
{
    int x = start ^ goal;
    int ans = 0;
    while (x > 0)
    {
        if (x & 1)
            ans++;
        x = x >> 1;
    }
    return ans;
}

int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (auto v : nums)
    {
        ans ^= v;
    }
    return ans;
}

vector<vector<int>> powerSet(vector<int> &nums)
{
    int len = nums.size();
    int subsets = 1 << len; // 2^len
    vector<vector<int>> result;
    for (int i = 0; i < subsets; i++)
    {
        vector<int> v;
        for (int j = 0; j < len; j++)
        {
            if (i & (1 << j))
            {
                v.push_back(nums[j]);
            }
        }
        result.push_back(v);
    }
    return result;
}

int main()
{
    // int n, m;
    // cin >> n;
    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    //     cin >> nums[i];
    // vector<int> ans = singleNumberIII(nums);
    // for (auto v : ans)
    //     cout << v << " ";
}