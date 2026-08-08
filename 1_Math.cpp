#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int armstrong(int n)
{
    int sum = 0;
    int temp = n;
    int i = 0;
    while (n)
    {
        int d = n % 10;
        n = n / 10;
        sum += (d * d * d);
    }
    return sum == temp;
}

vector<int> divisors(int n)
{
    vector<int> div;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void printNumbers(int n)
{
    if (n > 1)
    {
        printNumbers(n - 1);
    }
}
int NnumbersSum(int n)
{
    if (n >= 1)
    {
        return n + NnumbersSum(n - 1);
    }
    else
    {
        return 0;
    }
}
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
void reverse(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int reverseNumber(int x)
{
    int ans = 0;
    while (x != 0)
    {
        int digit = x % 10;

        // Check for overflow/underflow before updating ans
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
        {
            return 0;
        }
        ans = ans * 10 + digit;
        x = x / 10;
    }
    return ans;
}

bool palindromeCheck(string &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
int mostFrequentElement(vector<int> &nums)
{
    int maxnum = -1e9;
    int maxfreq = 0;
    unordered_map<int, int> mp;
    for (auto v : nums)
    {
        mp[v]++;
    }

    for (auto v : mp)
    {
        if (maxfreq < v.second)
        {
            maxnum = v.first;
            maxfreq = v.second;
        }
        else if (maxfreq == v.second)
        {
            if (maxnum > v.first)
            {
                maxnum = v.first;
            }
        }
    }
    return maxnum;
}
vector<int> selectionSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    return nums;
}

vector<int> bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    bool swap = false;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap = true;
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
        if (swap == false)
        {
            break;
        }
    }
    return nums;
}
vector<int> insertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
    return nums;
}
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
}
void mergeSortF(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSortF(nums, low, mid);
    mergeSortF(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
vector<int> mergeSort(vector<int> &nums)
{
    mergeSortF(nums, 0, nums.size() - 1);
    return nums;
}
int main()
{
    int n;
    cin >> n;
    // vector<int> arr;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     arr.push_back(x);
    // }
    // vector<int> res = mergeSort(arr);
    // for (auto v : res)
    // {
    //     cout << v << " ";
    // }
    cout << reverseNumber(n) << endl;
}