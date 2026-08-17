#include <bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i)
{
    if (n & 1 << i)
        return true;
    return false;
}

int main()
{
    int n, i;
    cin >> n >> i;
    cout << checkIthBit(n, i);
}