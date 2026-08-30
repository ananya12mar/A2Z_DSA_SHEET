#include <bits/stdc++.h>
using namespace std;

// very very inp
int longestNonRepeatingSubstring(string &s)
{
    vector<int> hash(256, -1);
    int maxLen = 0, left = 0, right = 0;
    while (right < s.size())
    {
        // if character at current index exists in the hash
        if (hash[s[right]] != -1)
        {
            // if within the correct range
            if (hash[s[right]] >= left)
            {
                // move left to that right_index + 1
                left = hash[s[right]] + 1;
            }
        }
        // find the length
        int len = right - left + 1;
        maxLen = max(len, maxLen);

        // set the right index in the hash
        hash[s[right]] = right;
        right++;
    }
    return maxLen;
}

// Approach 1
int longestOnes1(vector<int> &nums, int k)
{
    int zeros = 0;
    int left = 0, right = 0, maxLen = 0;
    while (right < nums.size())
    {
        if (nums[right] == 0)
            zeros++;

        // invalid subarray, make it valid by decreasing zeros in range
        while (zeros > k)
        {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        if (zeros <= k) // valid subarray
        {
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        right++;
    }
    return maxLen;
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
    cout << longestOnes1(v, k);
}
