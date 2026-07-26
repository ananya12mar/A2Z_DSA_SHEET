#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    string res = "";
    int level = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            if (level > 0)
                res += ch;
            level++;
        }
        else if (ch == ')')
        {
            level--;
            if (level > 0)
                res += ch;
        }
    }
    return res;
}
string reverseWords(string s)
{
    string result = "";
    int i = s.size() - 1;
    while (i >= 0)
    {
        while (i >= 0 && s[i] == ' ')
            i--;
        if (i < 0)
            break;
        int end = i;
        while (i >= 0 && s[i] != ' ')
            i--;
        string word = s.substr(i + 1, end - i);
        if (!result.empty())
            result += " ";
        result += word;
    }
    return result;
}

string largeOddNum(string &s)
{
    int lastOcc = -1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] % 2 != 0)
        {
            lastOcc = i;
            break;
        }
    }
    int cnt = 0;
    while (cnt <= lastOcc && s[cnt] == '0')
        cnt++;
    return s.substr(cnt, lastOcc - cnt + 1);
}

string longestCommonPrefix(vector<string> &str)
{
    if (str.empty())
        return "";
    sort(str.begin(), str.end());
    string first = str[0];
    string last = str[str.size() - 1];
    string ans = "";
    int minLength = min(first.size(), last.size());
    for (int i = 0; i < minLength; i++)
    {
        if (first[i] == last[i])
        {
            ans += first[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

bool isomorphicString(string s, string t)
{
    int m1[256] = {0}, m2[256] = {0};
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (m1[s[i]] != m2[t[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

bool rotateString(string &s, string &goal)
{
    if (s.length() != goal.length())
        return false;
    string doubleString = s + s;
    return doubleString.find(goal) != string::npos;
}

bool anagramStrings(string &s, string t)
{
    if (s.length() != t.length())
        return false;

    int freq[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << anagramStrings(s, t);
}