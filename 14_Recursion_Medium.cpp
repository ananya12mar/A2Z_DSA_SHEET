#include <bits/stdc++.h>
using namespace std;

void generate(vector<string> &result, int n, string curr)
{
    // base case: if length is n, then add to result
    if (curr.length() == n)
    {
        result.push_back(curr);
        return;
    }
    // always try adding 0
    generate(result, n, curr + '0');
    // add 1 is last occurence was not 1 or string was empty
    if (curr.empty() || curr.back() != '1')
    {
        generate(result, n, curr + '1');
    }
}
vector<string> generateBinaryStrings(int n)
{
    vector<string> result;
    generate(result, n, "");
    return result;
}

void generatePara(vector<string> &result, int n, string curr, int open, int close)
{
    if (curr.length() == (2 * n))
    {
        result.push_back(curr);
        return;
    }
    if (open < n)
        generatePara(result, n, curr + '(', open + 1, close);
    if (close < open)
        generatePara(result, n, curr + ')', open, close + 1);
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    generatePara(result, n, "", 0, 0);
    return result;
}

void generateSet(vector<vector<int>> &result, vector<int> &nums, int idx, vector<int> curr)
{
    if (idx == nums.size())
    {
        result.push_back(curr);
        return;
    }
    generateSet(result, nums, idx + 1, curr);

    curr.push_back(nums[idx]);
    generateSet(result, nums, idx + 1, curr);

    curr.pop_back();
}
vector<vector<int>> powerSet(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> curr;
    generateSet(result, nums, 0, curr);
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> ans = powerSet(a);
    for (auto v : ans)
    {
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
}