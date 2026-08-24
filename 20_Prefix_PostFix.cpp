#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}

int prec(char c)
{
    if (c == '^') // Exponent operator has highest precedence
        return 3;
    else if (c == '/' || c == '*') // Multiplication and division have higher precedence than addition
        return 2;
    else if (c == '+' || c == '-') // Addition and subtraction have lowest precedence
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < s.size())
    {
        if (isOperand(s[i]))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infixToPrefix(string str)
{
    string s = str;
    reverse(s.begin(), s.end());
    for (char &c : s)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < s.size())
    {
        if (isOperand(s[i]))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            // additional step to be remembered
            if (s[i] == '^')
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                // only < not <=
                while (!st.empty() && prec(s[i]) < prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string postToInfix(string postExp)
{
    int i = 0;
    stack<string> st;
    while (i < postExp.size())
    {
        if (isOperand(postExp[i]))
            st.push(string(1, postExp[i]));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string a = "(" + t2 + postExp[i] + t1 + ')';
            st.push(a);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string s = "AB*C+";
    cout << postToInfix(s) << endl;
}