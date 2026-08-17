#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void createPartition(string s, vector<vector<string>> &result, vector<string> curr, int idx)
{
    if (idx == s.size())
    {
        result.push_back(curr);
        return;
    }
    // starting index is idx
    // ending index is i

    // looping to all starting indexes
    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(idx, i, s))
        {
            string a = s.substr(idx, i - idx + 1);
            curr.push_back(a);
            createPartition(s, result, curr, i + 1);
            curr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> curr;
    createPartition(s, result, curr, 0);
    return result;
}

int main()
{
    string s;
    cin >> s;
    vector<vector<string>> ans = partition(s);
    for (auto v : ans)
    {
        for (auto e : v)
            cout << e << " ";

        cout << "\n";
    }
}