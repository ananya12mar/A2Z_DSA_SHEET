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

int subsequence(vector<int> &nums, int sum, int idx)
{
    // if sum is 0, one valid subsequence is found
    if (sum == 0)
        return 1;
    // if sum is negative or index exceeds array size
    if (sum < 0 || idx == nums.size())
        return 0;

    // Recurse by including current number or excluding it from the sum
    return subsequence(nums, sum - nums[idx], idx + 1) + subsequence(nums, sum, idx + 1);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k)
{
    return subsequence(nums, k, 0);
}

bool checkSubsequenceSum(vector<int> &nums, int k)
{
    int ans = subsequence(nums, k, 0);
    if (ans)
        return true;
    else
        return false;
}

void generateSetSum(vector<vector<int>> &result, vector<int> &candidates, int idx, vector<int> curr, int sum)
{
    if (idx == candidates.size())
    {
        if (sum == 0)
            result.push_back(curr);
        return;
    }
    if (candidates[idx] <= sum)
    {
        curr.push_back(candidates[idx]);
        // take the element and don't increase index as this element can be taken again
        generateSetSum(result, candidates, idx, curr, sum - candidates[idx]);
        curr.pop_back();
    }
    generateSetSum(result, candidates, idx + 1, curr, sum);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> curr;
    generateSetSum(result, candidates, 0, curr, target);
    return result;
}

void generateSetSumII(vector<vector<int>> &result, vector<int> &candidates, int idx, vector<int> &curr, int sum)
{
    if (sum == 0)
    {
        result.push_back(curr);
        return;
    }

    // Loop through the elements starting from index 'idx'
    for (int i = idx; i < candidates.size(); i++)
    {
        // Skip duplicates to avoid repeating combinations
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;

        // If the current element is greater than the remaining target, break the loop
        if (candidates[i] > sum)
            break;

        curr.push_back(candidates[i]);
        // Recur with the updated target and next index (i + 1 to avoid repetition)
        generateSetSumII(result, candidates, i + 1, curr, sum - candidates[i]);
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    generateSetSumII(result, candidates, 0, curr, target);
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // int res;
    // res = checkSubsequenceSum(a, k);
    // cout << res;
    vector<vector<int>> ans = combinationSum2(a, k);
    for (auto v : ans)
    {
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
}