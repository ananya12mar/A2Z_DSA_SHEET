#include <bits/stdc++.h>
using namespace std;

static bool comparator(pair<int, char> p1, pair<int, char> p2)
{
    if (p1.first > p2.first)
        return true;
    if (p1.first < p2.first)
        return false;
    return p1.second < p2.second;
}

vector<char> frequencySort(string &s)
{
    pair<int, char> freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = {0, i + 'a'};
    }

    for (char ch : s)
    {
        freq[ch - 'a'].first++;
    }

    sort(freq, freq + 26, comparator);

    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i].first > 0)
            ans.push_back(freq[i].second);
    }
    return ans;
}

int maxDepth(string s)
{
    int depthMax = 0;
    int curr = 0;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            curr++;
        }
        else if (ch == ')')
        {
            curr--;
        }
        depthMax = max(curr, depthMax);
    }
    return depthMax;
}

int main()
{
    string s;
    getline(cin, s);
    // vector<char> ans = frequencySort(s);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << maxDepth(s);
}