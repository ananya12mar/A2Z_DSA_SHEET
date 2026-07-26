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

int main()
{
    vector<string> s = {"flowers", "flow", "fly", "flight"};
    // getline(cin, s);
    cout << longestCommonPrefix(s);
}