#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<vector<int>> primeFactors(vector<int> &queries)
{
    vector<vector<int>> result;
    for (auto v : queries)
    {
        vector<int> factors;
        for (int i = 2; i * i <= v; i++)
        {
            if (v % i == 0)
            {
                while (v % i == 0)
                {
                    if (isPrime(i))
                        factors.push_back(i);
                    v = v / i;
                }
            }
        }
        if (v != 1)
            factors.push_back(v);
        result.push_back(factors);
    }
    return result;
}

vector<int> divisors(int n)
{
    vector<int> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

int main()
{
    int n;
    cin >> n;
    // cout << isPrime(n) << endl;
    // vector<int> nums(n);
    // for (int i = 0; i < n; i++)
    //     cin >> nums[i];
    vector<int> ans = divisors(n);
    for (auto v : ans)
    {
        cout << v << " ";
    }
}