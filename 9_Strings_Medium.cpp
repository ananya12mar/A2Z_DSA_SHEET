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

int romanToInt(string s)
{
    int ans = 0;
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    for (int i = 0; i < s.length(); i++)
    {
        if (roman[s[i]] >= roman[s[i + 1]])
        {
            ans += roman[s[i]];
        }
        else
        {
            ans -= roman[s[i]];
        }
    }
    return ans;
}

int myAtoi(string input)
{
    if (input.length() == 0)
        return 0;

    int i = 0;
    while (input[i] == ' ' && i < input.length())
    {
        i++;
    }
    input = input.substr(i);

    int sign = +1;
    long ans = 0;

    if (input[0] == '-')
        sign = -1;
    int MAX = INT_MAX;
    int MIN = INT_MIN;

    i = (input[0] == '+' || input[0] == '-') ? 1 : 0;

    while (i < input.length())
    {

        if (input[i] == ' ' || !isdigit(input[i]))
            break;

        ans = ans * 10 + input[i] - '0';

        if (sign == -1 && -1 * ans < MIN)
            return MIN;
        if (sign == +1 && ans > MAX)
            return MAX;

        i++;
    }
    return (int)(sign * ans);
}

int atMostKDistinct(string s, int k)
{
    int left = 0, res = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < s.size(); right++)
    {
        freq[s[right]]++;

        while (freq.size() > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }

        // Count substrings in current window
        res += (right - left + 1);
    }
    return res;
}
int countSubstrings(string s, int k)
{
    // Exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main()
{
    string s;
    int k;
    getline(cin, s);
    // cin.ignore();
    cin >> k;
    // vector<char> ans = frequencySort(s);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << countSubstrings(s, k);
}