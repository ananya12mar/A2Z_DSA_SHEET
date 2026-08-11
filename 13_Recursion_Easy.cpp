#include <bits/stdc++.h>
using namespace std;

int charToInt(string &input, int idx, long long num, int sign)
{
    if (idx > input.size() || !isdigit(input[idx]))
    {
        return (int)(sign * num);
    }

    num = num * 10 + (input[idx] - '0');

    if (sign * num <= INT_MIN)
        return INT_MIN;
    if (sign * num >= INT_MAX)
        return INT_MAX;

    // Recurse for next character
    return charToInt(input, idx + 1, num, sign);
}

int myAtoi(string input, int idx = 0)
{
    // Skip leading whitespaces
    while (idx < input.size() && input[idx] == ' ')
    {
        idx++;
    }

    // Handle sign
    int sign = 1;
    if (idx < input.size() && (input[idx] == '+' || input[idx] == '-'))
    {
        sign = (input[idx] == '-') ? -1 : 1;
        idx++;
    }

    return charToInt(input, idx, 0, sign);
}

int main()
{
    string s;
    getline(cin, s);
    // getline(cin, t);
    cout << myAtoi(s);
}