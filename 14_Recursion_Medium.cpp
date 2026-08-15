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

int main()
{
    int n;
    cin >> n;
    vector<string> ans = generateParenthesis(n);
    for (auto v : ans)
        cout << v << " ";
}