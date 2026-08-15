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

int main()
{
    int n;
    cin >> n;
    vector<string> ans = generateBinaryStrings(n);
    for (auto v : ans)
        cout << v << " ";
}