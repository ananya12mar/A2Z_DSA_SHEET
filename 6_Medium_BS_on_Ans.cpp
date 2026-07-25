#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n)
{
    int low = 1;
    int high = n;
    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long int val = mid * mid;
        if (val <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int multiply(int a, int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int NthRoot(int N, int M)
{
    int low = 1;
    int high = M;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = multiply(mid, N);
        if (val < M)
        {
            low = mid + 1;
        }
        else if (val == M)
        {
            return mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int func(vector<int> nums, int mid)
{
    int totalHours = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        totalHours += ceil((double)nums[i] / mid);
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> nums, int h)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (func(nums, mid) <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int bouquets(vector<int> nums, int mid, int k, int m)
{
    int count = 0;
    int curr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= mid)
        {
            curr++;
            if (curr == k)
            {
                count++;
            }
        }
        else if (nums[i] > mid)
        {
            curr = 0;
        }
    }
    return count;
}

int roseGarden(int n, vector<int> nums, int k, int m)
{
    if (nums.size() > m * k)
        return -1;
    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = bouquets(nums, mid, k, m);
        // cout<<"mid "<<mid<<" val "<<val<<" low "<<low<<" high "<<high<<endl;
        if (val < m)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int divisorSum(vector<int> nums, int mid)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += ceil((double)nums[i] / mid);
    }
    return ans;
}

int smallestDivisor(vector<int> &nums, int limit)
{
    if (nums.size() > limit)
        return -1;
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = divisorSum(nums, mid);
        if (val <= limit)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int daysFunc(vector<int> nums, int days, int mid)
{
    int count = 1;
    int curr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr += nums[i];
        if (curr > mid)
        {
            count++;
            curr = nums[i];
        }
    }
    return count;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = daysFunc(weights, days, mid);
        // cout<<"mid "<<mid<<" val "<<val<<endl;
        if (val < days)
        {
            high = mid - 1;
        }
        else if (val > days)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return ans;
}

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] - (mid + 1) < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1; // or return low+k;
}

bool canPlace(vector<int> nums, int n, int k, int mid)
{
    int count = 1;
    int last = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] - last >= mid)
        {
            count++;
            last = nums[i];
        }
        if (count >= k)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int low = 1;
    int n = nums.size();
    int high = nums[n - 1] - nums[0];
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlace(nums, n, k, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int canAssign(vector<int> &nums, int mid, int m)
{
    int curr = 0;
    int count = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        curr = curr + nums[i];
        if (curr > mid)
        {
            count++;
            curr = nums[i];
        }
    }
    return count;
}

int findPages(vector<int> &nums, int m)
{
    if (nums.size() < m)
        return -1;
    int low = *min_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canAssign(nums, mid, m) > m)
        {
            low = mid + 1;
        }
        else if (canAssign(nums, mid, m) <= m)
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int splits(vector<int> &a, int mid)
{
    int curr = 0;
    int count = 1;
    for (int i = 0; i < a.size(); i++)
    {
        curr = curr + a[i];
        if (curr > mid)
        {
            count++;
            curr = a[i];
        }
    }
    return count;
}
int largestSubarraySumMinimized(vector<int> &a, int k)
{
    if (a.size() < k)
        return -1;
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (splits(a, mid) > k)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int painters(vector<int> &C, int B, int mid)
{
    int curr = 0;
    int count = 1;
    for (int i = 0; i < C.size(); i++)
    {
        curr = curr + C[i] * B;
        if (curr > mid)
        {
            count++;
            curr = C[i] * B;
        }
    }
    return count;
}

int paint(int A, int B, vector<int> &C)
{
    int low = *max_element(C.begin(), C.end()) * B;
    int high = accumulate(C.begin(), C.end(), 0) * B;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (painters(C, B, mid) > A)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int numberOfGasStations(vector<int> &arr, long double mid)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / mid);
        if ((arr[i] - arr[i - 1]) / mid == numberInBetween * mid)
        {
            numberInBetween--;
        }
        count += numberInBetween;
    }
    return count;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)arr[i + 1] - arr[i]);
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStations(arr, mid);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

long double minimiseMax(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({(arr[i + 1] - arr[i]), i});
    }
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}

double median(vector<int> &arr1, vector<int> &arr2)
{
    if (arr2.size() < arr1.size())
        return median(arr2, arr1);
    int n1 = arr1.size();
    int n2 = arr2.size();
    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    if (b.size() < a.size())
        return kthElement(b, a, k);
    int n1 = a.size();
    int n2 = b.size();
    int low = max(0, k - n2), high = min(k, n1);
    int n = n1 + n2;
    int left = k;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;

        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}