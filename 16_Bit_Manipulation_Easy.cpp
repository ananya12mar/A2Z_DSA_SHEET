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

int main()
{
    int n, i;
    cin >> n >> i;
    cout << isPowerOfTwo(n);
}