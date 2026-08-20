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

vector<int> primesInRange(vector<vector<int>> &queries)
{
    if (queries.empty())
        return {};

    // Find the maximum value(second value) in the queries to determine the sieve range
    int maxVal = 0;
    for (auto query : queries)
        maxVal = max(maxVal, query[1]);

    // Use the Sieve of Eratosthenes to find all primes up to maxVal
    vector<bool> isPrime(maxVal + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes
    for (int p = 2; p * p <= maxVal; ++p)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= maxVal; i += p)
                isPrime[i] = false;
        }
    }

    // Create a prefix sum array to count primes up to each number
    vector<int> primeCount(maxVal + 1, 0);
    for (int i = 1; i <= maxVal; ++i)
    {
        primeCount[i] = primeCount[i - 1];
        if (isPrime[i])
        {
            primeCount[i]++;
        }
    }

    // Process each query to find the number of primes in the given range
    vector<int> result;
    for (auto query : queries)
    {
        int start = query[0];
        int end = query[1];
        if (start == 0)
            result.push_back(primeCount[end]);
        else
            result.push_back(primeCount[end] - primeCount[start - 1]);
    }
    return result;
}

int countPrimes(int n)
{
    // Sieve of eratosthenes
    if (n <= 2)
        return 0;

    vector<char> isPrime(n, 1);
    isPrime[0] = isPrime[1] = 0;

    int limit = (int)floor(sqrt(n - 1));

    for (int p = 2; p <= limit; ++p)
    {
        if (!isPrime[p])
            continue;

        long long start = 1LL * p * p;
        for (int i = (int)start; i < n; i += p)
            isPrime[i] = 0;
    }

    int cnt = 0;
    for (int i = 2; i < n; ++i)
        cnt += isPrime[i];

    return cnt;
}

double power(double x, int n)
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
double myPow(double x, int n)
{
    int num = n;
    if (num < 0)
    {
        // Calculate the power of -n and take reciprocal
        return (1.0 / power(x, -1 * num));
    }
    // If n is non-negative
    return power(x, num);
}

int main()
{
    int n;
    cin >> n;
    // cout << isPrime(n) << endl;
    vector<vector<int>> nums;
    nums.assign(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> nums[i][j];
    vector<int> ans = primesInRange(nums);
    for (auto v : ans)
    {
        cout << v << " ";
    }
}