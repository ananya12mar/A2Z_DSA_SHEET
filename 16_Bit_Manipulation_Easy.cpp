#include <bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i)
{
    if (n & 1 << i)
        return true;
    return false;
}

bool isOdd(int n)
{
    if (n & 1 << 0)
        return true;
    return false;
}

bool isPowerOfTwo(int n)
{
    if (n > 0 && !(n & n - 1))
        return true;
    return false;
}

int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n & n - 1; // Turn off the rightmost set bit
        count++;
    }
    return count;
}

int setRightmostUnsetBit(int n)
{
    return n | (n + 1);
}

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (divisor == 1)
        return dividend;

    bool isPositive = true;
    if (dividend >= 0 && divisor < 0)
        isPositive = false;
    else if (dividend < 0 && divisor > 0)
        isPositive = false;

    long long n = dividend;
    long long d = divisor;

    n = abs(n);
    d = abs(d);
    long long ans = 0, sum = 0;

    while (sum + d <= n)
    {
        ans++;
        sum += d;
    }

    if (ans > INT_MAX && isPositive)
        return INT_MAX;
    if (ans > INT_MAX && !isPositive)
        return INT_MIN;

    return isPositive ? ans : -ans;
}

int divideBM(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (divisor == 1)
        return dividend;
    bool isPositive = (dividend < 0 == divisor < 0);

    long long a = dividend;
    long long b = divisor;
    a = abs(a);
    b = abs(b);
    unsigned int ans = 0;

    while (a >= b)
    {
        short q = 0;
        while (a > (b << (q + 1)))
            q++;
        ans += (1 << q);
        a = a - (b << q);
    }
    if (ans == (1 << 31) and isPositive)
        return INT_MAX;
    return isPositive ? ans : -ans;
}

int main()
{
    int n, i;
    cin >> n >> i;
    int ans = divideBM(n, i);
    cout << ans;
}