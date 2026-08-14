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

double power(double x, long long n)
{
    if (n == 0)
        return 1.0;
    if (n == 1)
        return x;

    if (n % 2 == 0)
        return power(x * x, n / 2);
    else
        return x * power(x, n - 1);
}

double myPow(double x, long long n)
{
    if (n < 0)
    {
        return 1.0 / power(x, -n);
    }
    return power(x, n);
}

long long helper(long long base, long long expo, long long mod)
{
    long long ans = 1;
    while (expo > 0)
    {
        if (expo % 2 == 0)
        {
            base = (base * base) % mod;
            expo = expo / 2;
        }
        else
        {
            ans = (ans * base) % mod;
            expo -= 1;
        }
    }
    return ans;
}

int countGoodNumbers(long long n)
{
    long long even = (n + 1) / 2;
    long long odd = n / 2;
    long long mod = 1e9 + 7;
    return (int)((helper(5, even, mod) * helper(4, odd, mod)) % mod);
}

void insert(stack<int> &s, int temp)
{
    // if the stack is empty or temp is larger than the top element
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sortStack(stack<int> &s)
{
    if (!s.empty())
    {
        int temp = s.top();
        s.pop();

        sortStack(s);

        insert(s, temp);
    }
}

void insertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int topVal = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(topVal);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;
    int topVal = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topVal);
}

int main()
{
    // double x;
    long long n;
    cin >> n;
    cout << countGoodNumbers(n);
}